#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int copy(char *file_name, char *new_file_name){
    int fileSource, fileDest;
    void *src, *dst;
    struct stat file_stat;
    
    fileSource = open(file_name, O_RDONLY);
    if (fileSource == -1) {
        return -1;
    }

    if (fstat (file1,&file_stat) == -1) {
        close(fileSource);
        return -1;
    }
    
    fileDest = open(new_file_name, O_RDWR | O_CREAT | O_TRUNC, file_stat.st_mode);
    if (fileDest == -1) {
        close(fileSource);
        return -1;
    }

    if(ftruncate(fileDest, file_stat.st_size) == -1){
        close(fileSource);
        close(fileDest);
        return -1;
    }

    src = mmap(NULL, file_stat.st_size, PROT_READ, MAP_SHARED, fileSource, 0);
    if (src == (void *)(-1)) {
        close(fileSource);
        close(fileDest);
        return -1;
    }

    dst = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDest, 0);
    if (dst == (void *)(-1)) {
        close(fileSource);
        close(fileDest);
        munmap(src, file_stat.st_size);
        return -1;
    }

    memcpy(dst, src, file_stat.st_size);

    if(munmap(src,file_stat.st_size) == -1) {
        close(fileSource);
        close(fileDest);
        munmap(dst, file_stat.st_size);
        return -1;
    }

    if(munmap(dst,file_stat.st_size) == -1) {
        close(fileSource);
        close(fileDest);
        return -1;
    }
    
    if(close(file1) == -1) {
        close(fileDest);
        return -1;
    }

    if(close(file2) == -1) {
        return -1;
    }
    return 0;
}