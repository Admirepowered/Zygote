#include "linux/fs.h"
#include "linux/module.h"
#include "linux/workqueue.h"

#include "arch.h"
#include "core_hook.h"
#include "uid_observer.h"


int __init zygote_init(void)
{
#ifdef CONFIG_ZYGOTE_DEBUG
	pr_alert("*************************************************************");
	pr_alert("**     NOTICE NOTICE NOTICE NOTICE NOTICE NOTICE NOTICE    **");
	pr_alert("**                                                         **");
	pr_alert("**         You are running Zygote_Patch in DEBUG mode      **");
	pr_alert("**                                                         **");
	pr_alert("**     NOTICE NOTICE NOTICE NOTICE NOTICE NOTICE NOTICE    **");
	pr_alert("*************************************************************");
#endif


//#ifdef CONFIG_KPROBES
//	ksu_enable_sucompat();
//	ksu_enable_ksud();
//#else
//	pr_alert("KPROBES is disabled, KernelSU may not work, please check https://kernelsu.org/guide/how-to-integrate-for-non-gki.html");
//#endif

	return 0;
}

void zygote_exit(void)
{


	return;
}

module_init(zygote_init);
module_exit(zygote_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Admire");
MODULE_DESCRIPTION("Android Zygote_Patch");

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
MODULE_IMPORT_NS(VFS_internal_I_am_really_a_filesystem_and_am_NOT_a_driver);
#endif
