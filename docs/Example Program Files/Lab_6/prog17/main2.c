#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   printf("Alt program:getpid: %d  getpppid: %d\n", getpid(), getppid());
    printf("Ana program mesajı: %s\n", argv[0]);

    return 0;
}

