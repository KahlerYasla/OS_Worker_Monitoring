#include <stdio.h>

int main(int argc, char *argv[])
{

      /* write(2, "fatih", 5);
       perror("");*/
   int pipefd[2];
      int i;
      char s[1000];
      char *s2;

      if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
      }

      s2 = "fatih sultan mehmet";

      write(pipefd[1], s2, strlen(s2));

      i = read(pipefd[0], s, 1000);
      s[i] = '\0';
        printf("%d\n",pipefd[0]);
         printf("%d\n",pipefd[1]);

      printf("Pipe'tan %d byte Okundu:  '%s'\n", i, s);
    return 0;
}
