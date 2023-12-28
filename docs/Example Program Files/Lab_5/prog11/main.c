#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int i, j, status;

    i = fork();

    if (i > 0) {
      j = wait(&status);
      printf("Ana: Çocuk İşi Bitirdi.\n");
      printf("  Donen Deger : %d\n", j);
      printf("  Durum:       %d\n", status);
      printf("  WIFSTOPPED:   %d\n", WIFSTOPPED(status));
      printf("  WIFSIGNALED:  %d\n", WIFSIGNALED(status));
      printf("  WIFEXITED:    %d\n", WIFEXITED(status));
      printf("  WEXITSTATUS:  %d\n", WEXITSTATUS(status));
      printf("  WTERMSIG:     %d\n", WTERMSIG(status));
      printf("  WSTOPSIG:     %d\n", WSTOPSIG(status));
    } else {
      printf("Çocuk (%d) Çıkma Istegi Yapti exit(0)\n", getpid());
      exit(0);
    }
    return 0;
}
