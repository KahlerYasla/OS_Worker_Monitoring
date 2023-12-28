#include <stdio.h>

int main(int argc, char *argv[])
{

    int i;
    int fv;
        printf("Ana Proses: i= %d  getpid() = %d, getppid() = %d \n",i, getpid(), getppid());
    for (i = 0; i < 3; i++) {
      fv = fork();
exit(0); 
      printf("Proses: i= %d  getpid() = %d, getppid() = %d \n",i, getpid(), getppid());
     if (fv == 0) exit(0); // if şartını kapatıp tekrar deneyelim
    }
    return 0;
}
