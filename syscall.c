#include <sys/syscall.h>
#include <sys/types.h>


int mygettid(){
  int status;

  __asm__("movl $224, %eax");

  __asm__(“int $0x80");
  __asm__("movl %eax, -4(%ebp)");
  return status;
}


int main(){
  pid_t tid;

  tid = syscall(SYS_gettid);
}
