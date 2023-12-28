#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char ** envp)
{
    char *newargv[3];
      int i;

      newargv[0] = "cat";
      newargv[1] = "main.c"; // program calistigi dosyada herhangi bir dosya
      newargv[2] = NULL;
      //bin dosyasının altına bakın. Neler var? Neye benziyor?
      //cat programını çalıştırıyoruz
      printf("Ana program: Exec calisti\n");
      i = execve("/bin/cat", newargv, envp);
      perror("exec2: execve failed\n");
      printf("Ana program: Burasi yazacak mi?\n");
    return 0;
}
