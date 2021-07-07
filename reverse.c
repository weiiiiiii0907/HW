#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    int fd;
    int file_size = 0;

    fd = open(argv[1], O_RDWR);
    
    file_size = lseek(fd, 0, SEEK_END);

    for(int i = 0; i < file_size / 2; i++){
        char head[2] = {0};
        char tail[2] = {0};

        lseek(fd, i, SEEK_SET);
        read(fd, head, 1);

        lseek(fd, -1 * i - 1, SEEK_END);
        read(fd, tail, 1);

        lseek(fd, i, SEEK_SET);
        write(fd, tail, 1);

        lseek(fd, -1 * i - 1, SEEK_END);
        write(fd, head, 1);
    }

    close(fd);

    return 0;
}