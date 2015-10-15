#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dawid Urbanski");
MODULE_DESCRIPTION("Simple character device driver");

#include "deviceActions.c" //fops
#include "deviceCreation.c"

static int __init moduleInit(void)
{
  if(deviceCreate()!=0) return -1;

  return 0;
}
module_init(moduleInit);

static void __exit moduleExit(void)
{
  deviceDestroy();
}
module_exit(moduleExit);
