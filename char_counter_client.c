#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int fd;
    char buffer[100];
    fd=open("charCounter",O_WRONLY);
    if(fd<0){
        fprintf(stderr,"Error in opening file. Exiting\n");
        exit(-1);
    }
    printf("Enter message to send: ");
    fgets(buffer,sizeof(buffer),stdin);
    write(fd,buffer,strlen(buffer));
    fd=open("charCounter",O_RDONLY);
    read(fd,buffer,sizeof(buffer));
    printf("Number of characters: %s",buffer);
    close(fd);
}