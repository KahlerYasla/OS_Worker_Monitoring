/* This program forks off two threads which share an integer,
   on which there is a race condition. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//global degisken
int value=0;
void *threadfonk(int tid)
{

    for (int var = 0; var < 10000; ++var) {
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

    }

  return NULL;
}


int main(int argc, char **argv)
{
  int threadsayi=5;
  pthread_t tids[threadsayi];
  void * status;

  for (int var = 0; var < threadsayi; ++var) {
        pthread_create(tids+var, NULL, threadfonk, var);
  }

  for (int var = 0; var < threadsayi; ++var) {
       pthread_join(tids[var], &status);
  }


  exit(0);

  return 0;
}

