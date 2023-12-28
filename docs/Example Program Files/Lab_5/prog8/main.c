#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

     i = fork();
     if (i == 0) {
       printf("\nCocuk prosess.  getpid() = %d, getppid() = %d\n", getpid(), getppid());
       sleep(5);
       printf("\nUykunun Ardından.  getpid() = %d, getppid() = %d\n",
               getpid(), getppid());
     } else {
         printf("Anayım ben:  Benim pid= %d.  Anamın pid= %d\n",
          getpid(), getppid());

       printf("\nAnanın işi bitti\n");
     }
    return 0;
}
