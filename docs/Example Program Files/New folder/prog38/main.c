/* This program forks off two threads which share an integer,
   on which there is a race condition. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//global degisken
pthread_mutex_t lock;
int value=0;
void *threadfonk(int tid)
{

    for (int var = 0; var < 1000000; ++var) {
          pthread_mutex_lock(&lock);
       value=1;
       //sleep(tid);
       // sleep(1);
       if(value==0)
       printf("%d. Deneme %d. Thread Value Set= %d\n",var,tid, value);

       value=0;
      //sleep(tid);
      //sleep(1);
       if(value==1)
       printf("%d. Deneme %d. Thread Value Reset= %d\n",var, tid, value);
          pthread_mutex_unlock(&lock);

    }

  return NULL;
}


int main(int argc, char **argv)
{
  int threadsayi=10;
  pthread_t tids[threadsayi];
  void * status;

  if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init hatasi\n");
        return 1;
    }


  for (int var = 0; var < threadsayi; ++var) {
        pthread_create(tids+var, NULL, threadfonk, var);
  }

  for (int var = 0; var < threadsayi; ++var) {
       pthread_join(tids[var], &status);
  }

    pthread_mutex_destroy(&lock);
  exit(0);

  return 0;
}

