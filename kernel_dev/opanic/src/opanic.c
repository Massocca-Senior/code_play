#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/mtd/mtd.h>

#define MODULE_NAME "OPANIC"
#define MOUDLE_VER "v2.0"
#define OCRASH_FLAG "CRASH\n"
#define PART_NUM 10
#define PART_NAME "0:CRASH"
#define LOG_SIZE (1024 * 128)
#define SAVE_SIZE (1024 * 64)

static int access_count;

struct logbuffer{
	int buf_len;
	char buffer[LOG_SIZE];
};

struct printk_log {
	u64 ts_nsec;
	u16 len;
	u16 text_len;
	u16 dict_len;
	u8 facility;
	u8 flags:5;
	u8 level:3;
}
#ifdef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
__packed __aligned(4)
#endif
;

extern char *log_buf_addr_get(void);
extern unsigned int log_buf_len_get(void);

struct logbuffer logbuf = { 0, {0} };

struct mtd_info *g_mtd;

static void erase_callback(struct erase_info *done)
{
    wait_queue_head_t *wait_q = (wait_queue_head_t *)done->priv;
    wake_up(wait_q);
}

static int erase_write(struct mtd_info *mtd, unsigned long pos, int len, const char *buf)
{
	struct erase_info erase;
	DECLARE_WAITQUEUE(wait, current);
	wait_queue_head_t wait_q;
	size_t retlen;
	int ret;
	init_waitqueue_head(&wait_q);
	erase.mtd = mtd;
	erase.callback = erase_callback;
	erase.addr = pos;
	erase.len = len;
	erase.priv = (u_long)&wait_q;
	set_current_state(TASK_UNINTERRUPTIBLE);
	add_wait_queue(&wait_q, &wait);

	ret = mtd_erase(mtd, &erase);
	if (ret) {
		remove_wait_queue(&wait_q, &wait);
		return ret;
	}
	remove_wait_queue(&wait_q, &wait);
	ret = mtd_write(mtd, pos, len, &retlen, buf);
	if (ret)
		return ret;
	if (retlen != len)
		return -EIO;
	return 0;
}

static char *log_text(char *msg)
{
	return (char *)msg + sizeof(struct printk_log);
}

static int get_log_buffer(struct logbuffer *log)
{
	char *log_buf;
	unsigned int log_size;
	char *msg;
	struct printk_log *msg_tmp;
	unsigned int count = 0;

	log_buf = (char *)log_buf_addr_get();
	if (NULL == log_buf) {
		printk(KERN_ERR "%s:log_buf_addr_get is NULL, return -1\n", MODULE_NAME);
		return -ENXIO;
	}

	log_size = log_buf_len_get();
	msg = log_buf;
	memcpy(log->buffer, OCRASH_FLAG, 6);
	count += 6;

	while (count < LOG_SIZE) {
		msg_tmp = (struct printk_log *)msg;
		if (!msg_tmp->len)
			break;
		if ((count + msg_tmp->text_len) > LOG_SIZE)
			break;
		memcpy(log->buffer + count, log_text(msg), msg_tmp->text_len);
		msg += msg_tmp->len;
		count += msg_tmp->len;
		log->buffer[count] = '\n';
		count += 1;
	}

	logbuf.buf_len = count;
	return 0;
}

static int opanic_crash_log_handler(struct notifier_block *this,
		unsigned long event, void *ptr)
{
	int len;
	unsigned int  save_pos = 0;

	printk(KERN_INFO "%s enter %s\n", MODULE_NAME, __func__);

	if (access_count > 1) {
		printk(KERN_INFO "%s %s It's no need to say goodbye again!\n", MODULE_NAME, MOUDLE_VER);
		return 0;
	}

	access_count++;

	printk(KERN_INFO "%s %s Oh I am going to die!\n", MODULE_NAME, MOUDLE_VER);

	if (get_log_buffer(&logbuf) < 0) {
		printk(KERN_ERR "%s:Can't kmalloc, fail\n", MODULE_NAME);
		return -ENOMEM;
	}

	save_pos = (logbuf.buf_len > SAVE_SIZE) ? (logbuf.buf_len - SAVE_SIZE) : 0;

	memcpy(logbuf.buffer + save_pos, OCRASH_FLAG, 6);

	len = erase_write(g_mtd, 0, SAVE_SIZE, logbuf.buffer + save_pos);
	if (g_mtd->_sync != NULL) {
		g_mtd->_sync(g_mtd);
	}
	return 0;
}

static struct notifier_block opanic_block = {
	.notifier_call	= opanic_crash_log_handler,
	.priority	= INT_MAX,
};

static int __init opanic_init(void)
{
	printk(KERN_INFO "Init module %s %s \n", MODULE_NAME, MOUDLE_VER);
	access_count = 0;
	atomic_notifier_chain_register(&panic_notifier_list,
		&opanic_block);

	g_mtd = get_mtd_device(NULL, PART_NUM);
	/*
	g_mtd = get_mtd_device_nm(PART_NAME);
	*/
	if (!g_mtd) {
		printk(KERN_ERR "%s:Can't find CRASH parttion!\n", MODULE_NAME);
		return -ENOMEM;
	}

	return 0;
}

static void __exit opanic_exit(void)
{
	printk(KERN_INFO "Deinit module %s %s \n", MODULE_NAME, MOUDLE_VER);
	atomic_notifier_chain_unregister(&panic_notifier_list,
		&opanic_block);

}

module_init(opanic_init);
module_exit(opanic_exit);

MODULE_AUTHOR("Jack Ma <majian1@oppo.com>");
MODULE_DESCRIPTION("Crash log record and flag set moudle");
MODULE_LICENSE("GPL v2");
