#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
  int res,len;
  char buf[100];
  printf("Enter some word: ");
  scanf("%s",buf);
  res=open("myfifo",O_WRONLY);
  write(res,buf,100);
  res=open("myfifo",O_RDONLY);
  read(res,buf,100);
  printf("Recieved response: %s\n",buf);
  return 0;
}