#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#define Fifo_Ass "assignment"

void convert_into_upper(char *);

int main() {
int fd,check,read_len;
char read_storage[100];
char terminate[20];
mkfifo(Fifo_Ass, S_IFIFO|0640);
strcpy(terminate, "terminate");
fd = open(Fifo_Ass, O_RDWR);
while(1) {
read_len = read(fd, read_storage, sizeof(read_storage));
read_storage[read_len] = '\0';
printf("Server recieves \"%s\"\n",read_storage);
check=strcmp(read_storage, terminate);
if (check!=0) {
convert_into_upper(read_storage);
printf("Server sending back string in upper case \"%s\"\n",read_storage);
write(fd, read_storage, strlen(read_storage));
sleep(2);
}
else{
close(fd);
break;
}
}
return 0;
}

void convert_into_upper(char *str){
int i;
for(i=0;str[i];i++){
if(str[i]>=97 && str[i]<=122)
str[i]=str[i]-32;
}
}

