#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.pb-c.h"


int main(int argc ,char *argv[])
{
    uint8_t data_buf[256] = {0};
    //char *cmdline = "noinitrd ro rootwait console=ttyMSM0,115200,n8 androidboot.hardware=qcom msm_rtb.filter=0x237 androidboot.console=ttyMSM0 lpm_levels.sleep_disabled=1 firmware_class.path=/lib/firmware/updates service_locator.enable=1 net.ifnames=0 rootfstype=ubifs rootflags=bulk_read root=ubi0:rootfs ubi.mtd=22 androidboot.serialno=c2793096 androidboot.baseband=msm";
    char *cmdline = "noinitrd ro rootwait console=ttyMSM0,115200,n8 androidboot.hardware=qcom";
    char *start = NULL;
    unsigned long lx;



    start = strstr(cmdline, "ubi.mtd=22");

    printf("size of unsigned long %ld\n", sizeof(unsigned long));

    if(start){
        printf("%s, %p\n", start, &start);
    }

    printf("Hello man\n");

    int data_len = 0;
    Msg msg;
    Msg *upk_msg = NULL;

    msg__init(&msg);

    msg.type = MESSAGE_TYPE__MSG_REP;
    msg.seq = 10;
    msg.data_type = 1;
    msg.data.len = strlen(cmdline);
    msg.data.data = malloc(msg.data.len + 1);
    memset(msg.data.data, 0, msg.data.len + 1);
    memcpy(msg.data.data, cmdline, msg.data.len);

    data_len = msg__pack(&msg,data_buf);

    printf("msg data pack len is %d\n", data_len);

    upk_msg = msg__unpack(NULL, data_len, data_buf);

    printf("type:%d, seq:%d, data_type:%d, data_len:%ld\ndata_data:%s \n", \
            upk_msg->type, upk_msg->seq, upk_msg->data_type,upk_msg->data.len, upk_msg->data.data);

    msg__free_unpacked(upk_msg,NULL);

    
    return 0;
}