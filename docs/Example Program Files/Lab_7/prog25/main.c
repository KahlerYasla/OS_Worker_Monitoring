#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
char *convert(int number)
{
    int count=0;
    int numbertmp=number;
    while(numbertmp>0)
    {
        int digit= numbertmp%10;
        numbertmp/=10;
        count++;
    }
    char * value= (char * ) calloc (count,sizeof(unsigned char)  );
    numbertmp=number;
    count--;
    while(numbertmp>0)
    {
        int digit= numbertmp%10;
        numbertmp/=10;
        char x=(char) 48+digit;
        *(value+count)=x;
        count--;
    }

    return value;
}

void sigpipe_handler(int dummy)
{
      printf("%d: pid bir SIGPIPE yakaladı\n", getpid());
      perror("");
  fprintf(stderr, "%d: pid bir SIGPIPE yakaladı\n", getpid());

  //exit(1);
}

main()
{
    int pipefd[2];
      int pid;
      int i, line;
      char s[1000];
       int c;

      if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
      }
      char *newargv[2];
       newargv[0] =  "convert(pipefd[0])";
       newargv[1] =  "convert(pipefd[1])";

       newargv[2] = NULL;
      pid = fork();

      if (pid == 0) {
          /*
        while(fgets(s, 1000, stdin) != NULL) {
          write(pipefd[1], s, strlen(s));
        }*/
          c = execve("prog25_2", newargv);
          perror("");
        close(pipefd[1]);
      } else {

          wait(&c);
                printf("Ana program:getpid: %d  getpppid: %d\n", getpid(), getppid());
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

