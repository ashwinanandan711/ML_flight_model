#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE(GPL); // GPL = GNU General Purpose License 

static int hello_world_init(void)
{
   printk(KERN_INFO "Hello, world\n"); //NOT PRINTF. printk() "prints" the statement in the kernel's ring buffer & is visible in the kernel logs
   return 0;
}

static void hello_world_exit(void)
{
   printk(KERN_INFO "Goodbye, world\n"); //mentioned log type or else it'll throw warnings.
}

module_init(hello_world_init);  //Function to be called when the module is loaded. 
module_exit(hello_world_exit);  //Function to be called when the module is unloaded

/* In Linux, kernel modules (LKMs) can be added or removed from the kernel space during runtime.
   And you can call certain functions to signify the loading and unloading of the LKM.*/

/* Module init functions need to have an integer return type because return 0 tells the kernel that
   the module initialization was a success. Any other value less than zerotells the kernel that the 
   init failed and the kernel proceeds to deallocate the memory allotted already and unloads the module.*/

/* if you don't want to mention log types, then you can use functions like pr_info(), pr_debug(), pr_err()
   pr_warn() and pr_notice() and allow the log level to be automatically set*/