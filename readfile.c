#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
  int fd = -1;
  char buffer[4096] = {0};
  int ret = 0;

  if(argc != 2){
    printf("Please provide the filename as argument to read\n");
    exit(EXIT_FAILURE);
  }

  fd = open("./signal.c", O_RDONLY);

  if(fd == -1){
    printf("Error in opening the file error_num=%d error=%s\n", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  while(ret = read(fd, (void *)buffer, sizeof(buffer)) > 0){
    printf("%s", buffer);
    memset(buffer, 0, sizeof(buffer));
  }

  close(fd);

  return EXIT_SUCCESS;
}
