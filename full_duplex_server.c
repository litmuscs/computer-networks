#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h> // Include for strlen

#define CTOS "clientToServer"
#define STOC "serverToClient"

void* serverWrites() {
    char buffer[100];
    while (1) {
        printf("\nSend a message to client: ");
        fgets(buffer, sizeof(buffer), stdin);

        int fd = open(STOC, O_WRONLY);
        if (fd == -1) {
            perror("open STOC");
            continue; // Try again in the next iteration
        }

        write(fd, buffer, strlen(buffer) + 1); // Write including null terminator
        close(fd);
    }
    return NULL;
}

void* serverReads() {
    char buffer[100];
    while (1) {
        int fd = open(CTOS, O_RDONLY);
        if (fd == -1) {
            perror("open CTOS");
            continue; 
        }

        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
        if (bytesRead > 0) {
            printf("\nReceived message: %s\n", buffer);
        }
        close(fd);
    }
    return NULL;
}

int main() {
    if (mkfifo(CTOS, 0666) == -1) {
        perror("mkfifo CTOS");
    }
    if (mkfifo(STOC, 0666) == -1) {
        perror("mkfifo STOC");
    }

    pthread_t readThread, writeThread;

    if (pthread_create(&readThread, NULL, serverReads, NULL) != 0) {
        fprintf(stderr, "Error creating read thread. Exiting\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&writeThread, NULL, serverWrites, NULL) != 0) {
        fprintf(stderr, "Error creating write thread. Exiting\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(readThread, NULL);
    pthread_join(writeThread, NULL);

    return 0;
}