//getpid ve getppid anlatımı programı

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Benim pid = %d.  Anamın-Babamın pid = %d\n", getpid(), getppid());
    return 0;
}
