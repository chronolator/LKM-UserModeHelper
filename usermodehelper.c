#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

/* Define Preprocessing */
#define MODULE_NAME 		"UserModeHelper"
#define LICENSE			"GPL"
#define AUTHOR			"Chronolator"
#define DESCRIPTION		"LKM example of executing a userland program."
#define VERSION			"0.01"

/* Module meta data */
MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);

/* Function Prototypes */
static void UserProc(void);

/* Execute a Userland Process/Program */
static void UserProc(void) {
    int ret = 0;
    char prog[] = "/usr/bin/wall";

    // argv = /usr/bin/wall -n Hello From UserModeHelper
    char *argv[] = { prog, "-n", "Hello From UserModeHelper", NULL };
    char **temp = argv;
    char *envp[] = { "HOME=/", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL };

    printk(KERN_INFO "%s module: The command", MODULE_NAME);
    printk(KERN_INFO "======================");
    while(*temp != NULL) {
        printk(KERN_INFO "%s", *temp);
        temp++;
    }
    printk(KERN_INFO "======================");
    printk(KERN_INFO "is executing\n");

    ret = call_usermodehelper(prog, argv, envp, UMH_WAIT_EXEC);
    if(ret != 0)
      printk(KERN_INFO "%s module: An unexpected error has occured when executing: \"%s\"\n", MODULE_NAME, prog);
    else
      printk(KERN_INFO "%s module: Binary \"%s\" has been executed successfully\n", MODULE_NAME, prog);
}

/* Init */
static int __init run_init(void) {
    printk(KERN_INFO "%s module: Initializing module\n", MODULE_NAME);

    UserProc();
    return 0;
}

/* Exit */
static void __exit run_exit(void) {
    printk(KERN_INFO "%s module: Exiting module\n", MODULE_NAME);

    return;
}

module_init(run_init);
module_exit(run_exit);
