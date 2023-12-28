/* This program forks off two threads which share an integer,
   on which there is a race condition. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>  /* Semaphore */

//global degisken
sem_t lock;
int value=0;
void *threadfonk(int tid)
{
     sem_wait(&lock);
     printf("%d. Thread Kiritik Bolgede\n",tid);
     sleep(4);
     sem_post(&lock);
      printf("%d. Thread Kiritik Bolgeden Cikti\n",tid);
     return NULL;
}


int main(int argc, char **argv)
{
  int threadsayi=5;
  pthread_t tids[threadsayi];
  void * status;

  if (sem_init(&lock, 0, 2) != 0)
    {
        printf("\n semafor init hatasi\n");
        return 1;
    }


  for (int var = 0; var < threadsayi; ++var) {
        pthread_create(tids+var, NULL, threadfonk, var);
  }

  for (int var = 0; var < threadsayi; ++var) {
       pthread_join(tids[var], &status);
  }

  sem_destroy(&lock);
  exit(0);

  return 0;
}

