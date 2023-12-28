#include <stdio.h>

 static int i=0;
int main(int argc, char *argv[])
{


    fork();
    i=1;
    fork();
    i=2;
    fork();
    i=3;
    i++;

    printf("Proses: i= %d \n",i);
    return 0;
}
