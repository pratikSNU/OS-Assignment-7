#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#define Fifo_Ass "assignment"

int main(){
int fd,check1,stringLength,readLen;
char read_storage[100];
char terminate_str[20];
fd = open(Fifo_Ass, O_CREAT|O_RDWR);
strcpy(terminate_str, "terminate");
while (1) {
printf("Enter string: ");
fgets(read_storage, sizeof(read_storage), stdin);
stringLength = strlen(read_storage);
read_storage[stringLength - 1] = '\0';
check1=strcmp(read_storage, terminate_str);
if (check1 != 0) {
write(fd, read_storage, strlen(read_storage));
printf("Client sends \"%s\"\n",read_storage);
readLen= read(fd, read_storage, sizeof(read_storage));
read_storage[readLen] = '\0';
printf("Client recieves \"%s\"\n",read_storage);
} 
else {
write(fd, read_storage, strlen(read_storage));
printf("Client sends \"%s\"\n",read_storage);
close(fd);
break;
}
}
return 0;
}

