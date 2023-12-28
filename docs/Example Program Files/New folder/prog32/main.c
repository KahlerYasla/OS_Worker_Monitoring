#include <pthread.h>
#include <stdio.h>

void *printme(void *ip)
{
 int *i;

 i = (int *) ip;
 printf("Merhaba.  Ben Thread:  %d\n", *i);
 return NULL;
}

int main()
{
 int i, vals[4];
 pthread_t tids[4];
 void *retval;

 for (i = 0; i < 4; i++) {
   vals[i] = i;
   pthread_create(tids+i, NULL, printme, vals+i);
 }

 for (i = 0; i < 4; i++) {
   printf("tid ile join oluyor %d\n", i);
   pthread_join(tids[i], &retval);
   printf("tid ile join oldu %d\n", i);
 }


 return 0;
}
