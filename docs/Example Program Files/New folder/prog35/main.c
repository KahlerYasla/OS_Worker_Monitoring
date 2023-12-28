#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printme1()
{
    for (int var = 0; var < 10; ++var) {
       printf("1>> %d.\n",var);
       sleep(1);
    }
  return NULL;
}



void *printme2()
{
    for (int var = 0; var < 10; ++var) {
       printf("2>> %d.\n",var);
       if(var==4)
       {
            //pthread_exit(0);
           exit(0);
       }
       sleep(1);
    }
  return NULL;
}
int main()
{
  pthread_t tcb1;
   pthread_t tcb2;
  void *status;

  if (pthread_create(&tcb1, NULL, printme1, NULL) != 0) {
    perror("thread olusturulamadi");
    exit(1);
  }
  if (pthread_create(&tcb2, NULL, printme2, NULL) != 0) {
    perror("thread olusturulamadi");
    exit(1);
  }

  if (pthread_join(tcb1, &status) != 0) { perror("pthread_join"); exit(1); }

  if (pthread_join(tcb2, &status) != 0) { perror("pthread_join"); exit(1); }
   printf("Bitti\n");
  return 0;
}
