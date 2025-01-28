#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stddef.h>  
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(){
    int fd;
    char buffer[100];

    fd=mkfifo("charCounter",0766);
    if(fd==-1){
        fprintf(stderr,"Error opening file\n");
        exit(-1);
    }
    fd=open("charCounter",O_RDONLY);
    unsigned int charsRead=read(fd,buffer,100);
    int len=strlen(buffer)-1;
    printf("Read %d characters: %s\n\n",len,buffer);
    fd=open("charCounter",O_WRONLY);
    char lenStr[10];
    sprintf(lenStr,"%d",len);
    write(fd,lenStr,strlen(lenStr)+1);
    close(fd);
    return 0;
}