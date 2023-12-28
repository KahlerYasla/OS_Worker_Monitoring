#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char ** envp)
{
    char *newargv[2];
      int i;

      newargv[0] = "Naber";
      newargv[1] = NULL;


          printf("Ana program: Exec calisti\n");
          i = execve("yok", newargv, envp);
          perror("exec: execve hata\n");



    return 0;
}
