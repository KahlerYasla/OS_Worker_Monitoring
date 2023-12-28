#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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

void *printme()
{
    int fd= open("dosya.txt", O_CREAT |O_WRONLY | O_APPEND,0777  );
    //perror("");
    for (int var = 0; var < 10; ++var) {
       printf("%d.\n",var);
       char * buffer=convert(var);
       size_t n= strlen(buffer);
       write(fd,buffer,n);
      // perror("");
       sleep(1);
    }
    fclose(fd);
    return NULL;
}

int main()
{
  pthread_t tcb;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

  if (pthread_create(&tcb, NULL, printme, NULL) != 0) {
    perror("thread olusturulamadi\n");
    exit(1);
  }
   printf("Thread Oluştu\n");
  for (int var = 0; var < 3; ++var) {
    sleep(1);
  }
printf("For bitti\n");
 pthread_detach(tcb);
printf("Thread Serbest Bırakıldı\n");
/*
for (int var = 0; var < 4; ++var) {
  sleep(1);
}*/
  return 0;
}

