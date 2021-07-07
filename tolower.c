#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
int main(int argc, char **argv){
    char buf[1024];
    int read_size = 0;

    int fd_in, fd_out;
    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[1], O_WRONLY | O_CREAT, 00600);

    if(fd_in == -1){
        printf("Open file failed.");
        return 0;
    }
    if(fd_out == -1){
        printf("Open file failed.");
        return 0;
    }

    while(1){
        read_size = read(fd_in, buf, 1024);
        for(int i=0;i<read_size;i++){
            if(isupper(buf[i])) buf[i]=tolower(buf[i]);
        }
        if(read_size <= 0) break;

        write(fd_out, buf, read_size);
    }
    close(fd_in);
    close(fd_out);

    return 0;

}