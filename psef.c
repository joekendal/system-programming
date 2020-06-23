#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage long sys_psef(void){
    struct task_struct *task_list;

    for_each_process(task_list){
      printk(KERN_INFO "%d\t\t%s\t\t%d\t%ld\t%d\n",
        task_list->pid,
        task_list->comm,
        task_list->tgid,
        task_list->state,
        task_list->prio);
    }
    return 0;
}
