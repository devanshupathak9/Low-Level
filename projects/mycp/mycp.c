#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096
char buffer[BUF_SIZE];
ssize_t bytes_read;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("open source");
        return 1;

    }
    int dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        perror("open destination");
        close(src_fd);
        return 1;
    }
    while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
        ssize_t bytes_written = 0;
        while (bytes_written < bytes_read) {
            ssize_t ret = write(dst_fd, buffer + bytes_written, bytes_read - bytes_written);
            if (ret < 0) {
                perror("write");
                close(src_fd);
                close(dst_fd);
                return 1;
            }
            bytes_written += ret;
        }
        if (bytes_read < 0) {
            perror("read");
        }
    }
    close(src_fd);
    close(dst_fd);
    return 0;
}