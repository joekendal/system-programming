#include <stdio.h>
#include <unistd.h>

int main(){
  pid_t pid;

  // clone
  if((pid = fork()) > 0){
    // parent process
    sleep(5)
  } else {
    // child process
    sleep(3)
  }

  return 0;
}
