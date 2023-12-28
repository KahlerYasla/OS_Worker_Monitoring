#include <stdio.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
      int pid;
      int i, line;
      char s[1000];

      if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
      }

      pid = fork();

      if (pid > 0) {
        while(fgets(s, 1000, stdin) != NULL) {
          write(pipefd[1], s, strlen(s));
        }
        close(pipefd[1]);
      } else {
        i = 0;
        line = 1;
        while(read(pipefd[0], s+i, 1) == 1) {
          if (s[i] == '\n') {
            s[i] = '\0';
            printf("%6d  %s\n", line, s);
            line++;
            i = 0;
          } else {
            i++;
          }
        }
      }
      return 0;
}
