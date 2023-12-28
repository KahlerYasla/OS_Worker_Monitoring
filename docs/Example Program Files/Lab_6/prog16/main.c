#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char ** envp)
{
    char *newargv[2];
      int i;

      newargv[0] = "Naber";
      newargv[1] = NULL;

      printf("Ana program:getpid: %d  getpppid: %d\n", getpid(), getppid());
      printf("Ana program: Exec calisti\n");
      i = execve("prog16_2", newargv, envp);
      perror("exec2: execve failed\n");
      printf("Ana program: Donus oldu mu?\n");
    return 0;
}
