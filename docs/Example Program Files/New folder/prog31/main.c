#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printme()
{
  printf("merhaba dunya\n");
  for (int var = 0; var < 10; ++var) {
      sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t tcb;
  void *status;

  if (pthread_create(&tcb, NULL, printme, NULL) != 0) {
    perror("thread olusturulamadi");
    exit(1);
  }
//  if (pthread_join(tcb, &status) != 0) { perror("pthread_join"); exit(1); }

    printf("bitti\n");
  return 0;
}
