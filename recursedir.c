#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* recursive file traversal */
void listdir(const char *pathname){
  DIR *dp;
  struct dirent *dirp;
  char PATH[259] = {0};

  if((dp = opendir(pathname)) == NULL)
    return;

  while((dirp = readdir(dp)) != NULL){
    if(dirp->d_type == DT_DIR){
      if((strcmp(dirp->d_name,".")==0) || (strcmp(dirp->d_name,"..")== 0))
        continue;

      printf("%s%s\n", pathname, dirp->d_name);
      snprint(PATH, sizeof(PATH)-1, "%s/%s", pathname, dirp->d_name);
      listdir(PATH);
    } else {
      printf("%s\n", dirp->d_name);
    }
  }
  closedir(dp);
}

int main(int argc, char *argv[]){
  listdir(argv[1]);
}
