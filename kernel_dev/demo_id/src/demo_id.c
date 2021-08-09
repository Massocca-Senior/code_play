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
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

#define MODULE_NAME "DEMO_ID"
#define MOUDLE_VER "v1.0"

static int demo_id_probe(struct platform_device *pdev)
{
	printk(KERN_INFO "%s Startting probe\n", MODULE_NAME);


	printk(KERN_INFO "%s Finish probe\n", MODULE_NAME);
	return 0;
}

static int demo_id_remove(struct platform_device *pdev)
{
	printk(KERN_INFO "Remove the driver of %s from kernel\n", MODULE_NAME);
	return 0;
}

struct of_device_id of_demo_tbls[] = {
	{.compatible = "0x001,demo_id"},
	{},
};

static struct platform_driver plat_demo_drv = {
	.probe = demo_id_probe,
	.remove = demo_id_remove,
	.driver = {
		.name = MODULE_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_demo_tbls,
	},
};

static int __init demo_id_init(void)
{
	int ret;
	printk(KERN_INFO  "Init the demo id driver\n");
	ret = platform_driver_register(&plat_demo_drv);

	printk(KERN_INFO "Platfrom driver regsiter status %d\n", ret);
	return ret;
}

static void __exit demo_id_exit(void)
{
	printk(KERN_INFO "Deinit the demo id driver\n");
	
}

module_init(demo_id_init);
module_exit(demo_id_exit);

MODULE_AUTHOR("Jack Ma <majian1@oppo.com>");
MODULE_DESCRIPTION("Module for of_match and id table test");
MODULE_LICENSE("GPL v2");
