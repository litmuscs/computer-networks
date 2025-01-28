#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
  int res,len;
  char buf[100];
  res=mkfifo("myfifo",0766);
  if(res==0){
    printf("Set up FIFO  successfully\n");
  }
  res=open("myfifo",O_RDONLY);
  read(res,buf,100);
  printf("The data is %s\n",buf);
  printf("Enter word to send to client: ");
  scanf("%s",buf);
  res=open("myfifo",O_WRONLY);
  write(res,buf,100);
  return 0;
}