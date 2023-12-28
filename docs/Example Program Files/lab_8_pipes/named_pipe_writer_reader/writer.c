// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int fd;
    FILE * fl;
    char * myfifo = "/tmp/writer";
 
    mkfifo(myfifo, 0666);
 
    char arr1[80];
    //fl= fopen("filename","w+");
    int count =0;
    
    while (1)
    {

        fd = open(myfifo, O_RDONLY);
        read(fd, arr1, sizeof(arr1));//blocking
        //arr1="merhaba\n";
	count++;
	printf("%d. read : %s\n",count,arr1);
	fl= fopen("filename.txt","a+");
        fprintf(fl,"%s", arr1);
        fclose(fl);
        close(fd);
    }
    return 0;
}
