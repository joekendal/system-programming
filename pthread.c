#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *ThreadFunc(void *args){
  printf("This is from the thread\n");
}

int main(){
  pthread_t mythread;
  void *thread_result;

  pthread_create(&mythread, NULL, ThreadFunc, NULL);

  printf("Thread ended\n");

  pthread_join(mythread, &thread_result);

  return 0;
}
