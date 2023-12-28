#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char ** envp)
{
    char *newargv[2];
      int i;

      newargv[0] = "Naber";
      newargv[1] = NULL;

      printf("Ana program:getpid: %d  getpppid: %d\n", getpid(), getppid());
      int f;
      f= fork();
      if(f==0)
      {
          printf("Ana program: Exec calisti\n");
          i = execve("prog17_2", newargv, envp);
          perror("exec2: execve failed\n");

      }
      else
      {
          printf("Ana program: Donus oldu mu?\n");

      }


    return 0;
}
