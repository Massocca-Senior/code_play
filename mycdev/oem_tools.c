#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define GPIO_ACTION "gpio_act"
#define TEST "do_test"

#define BASE_ADDR  0x1000

#define GPIO_ACTION_CONFIG_ADDR (BASE_ADDR + 0x0)
#define TEST_ADDR  (BASE_ADDR + 0x1000)

#define LED_BLINK_INTERVAL 1

//#define DEV_PATH "/dev/mtdblock9"
#define DEV_PATH "a.bin"

struct gpio_action
{
    unsigned int gpio_num;
    unsigned char action;
    unsigned char interval;
}__attribute__((packed));

struct gpio_action led_gpio;

int mtd_write(void *data, int data_len, int offset)
{
    int ret = 0;
    FILE *dfd = fopen(DEV_PATH, "wb+");
    if(dfd == NULL){
        printf("open file %s failed for %s",DEV_PATH, strerror(errno)); 
        return -1;
    }
    fseek(dfd, offset, SEEK_SET);    
    ret = fwrite(data, data_len, 1 ,dfd);
    fclose(dfd);
    return ret;
}

int mtd_read(void *data, int data_len, int offset)
{
    int ret = 0;
    FILE *dfd = fopen(DEV_PATH, "rb+");
    if(dfd  == NULL){
        printf("open file %s failed for %s",DEV_PATH, strerror(errno)); 
        return -1;
    }

    fseek(dfd, offset, SEEK_SET);    
    ret = fread(data, 1, data_len, dfd);
    fclose(dfd);
    return ret;
}

int do_gpio_action_define(int argc, char *argv[])
{
    int ret = 0;
    printf("do gpio action \n");
    printf("size of led gpio %ld\n", sizeof(led_gpio));
    if (argc >= 2) {
        if (strncmp("set", argv[1], strlen(argv[1])) == 0){
            if (argc < 3) {
                printf("usage: %s <set> <gpio num> <action> [interval \
                default is 1 when action is 2]\n", GPIO_ACTION);
                return -1;
            }
            led_gpio.gpio_num = atoi(argv[2]);
            led_gpio.action = atoi(argv[3]);
            if(argc < 4){
                led_gpio.interval = LED_BLINK_INTERVAL;
            }else
            {
                led_gpio.interval = atoi(argv[4]);
            }
            ret = mtd_write(&led_gpio,sizeof(led_gpio), GPIO_ACTION_CONFIG_ADDR);
            printf("gpio_num:%d, action:%d, interval:%d\n",
                led_gpio.gpio_num, led_gpio.action, led_gpio.interval);
        }
    }else{
        ret = mtd_read(&led_gpio,sizeof(led_gpio), GPIO_ACTION_CONFIG_ADDR);
        printf("gpio_num:%d, action:%d, interval:%d\n",
            led_gpio.gpio_num, led_gpio.action, led_gpio.interval);
    }
}

int do_test(int argc, char *argv[])
{
    int ret;
    char *data = "Hello man!";
    int data_len = strlen(data);

    printf("do test action %d\n", data_len);
    if (argc >= 2 ){
        if(strncmp("set", argv[1], strlen(argv[1])) == 0){
            ret = mtd_write(data, data_len, TEST_ADDR);
        }
    }else{
        char rdata[32] = {0};
        ret = mtd_read(rdata, data_len, TEST_ADDR);
        printf("rdata is:%s\n", rdata);
    }
    return ret;

}

int main (int argc, char *argv[])
{
    int ret = 0;   
    if (strncmp(GPIO_ACTION, argv[0], strlen(argv[0])) == 0){
        ret = do_gpio_action_define(argc, argv);
    } else if (strncmp(TEST, argv[0], strlen(argv[0])) == 0){
        ret = do_test(argc, argv);
    }

    return ret;
}