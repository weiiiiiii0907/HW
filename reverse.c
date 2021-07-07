#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void remove_newline(char *ptr){
    char *qtr=strchr(ptr,'\n');
    if(qtr) *qtr='\0';
}

int main(int argc, char **argv){
    int cnt=0;
    char buf[1024],word[1024];
    int fd_in, fd_out;
    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[1], O_WRONLY | O_CREAT, 00600);
    int read_size=0;
    while(1){
        read_size = read(fd_in, buf, 1024);
        if(read_size <= 0) break;
        cnt=read_size-1;
        for(int i=0;i<read_size;i++){
            word[i]=buf[i];
        }
        for(int i=0;i<read_size;i++){
            word[cnt-i]=buf[i];
        }
        remove_newline(word);
        write(fd_out,word,read_size);
    }
    close(fd_out);
    close(fd_in);
    return 0;
}