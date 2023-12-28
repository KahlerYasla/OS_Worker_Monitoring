#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

      printf("Parent Ben : pid = %d\n", getpid());
      i = fork();
      printf("Fork oldu:  Fork id= %d. benim pid= %d.  MyParent pid= %d\n",
        i, getpid(), getppid());
    return 0;
}
