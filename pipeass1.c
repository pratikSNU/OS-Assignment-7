#include<stdio.h>
#include<unistd.h>
int main(){
int pid;
int fd[2];
int status;
char writeMessege[20]={"Hi"};
char readMessege[20];
int writeNum=10;
int readNum;
status=pipe(fd);
if(status==-1){                           
printf("Pipe creation failed\n");               //checking if pipe is created or not
return 1;
}
pid=fork();
if(pid<0){
perror("Child creation failed\n");              //checking if child process is created or not  
return 1;
}
if(pid==0){
write(fd[1],writeMessege,sizeof(writeMessege));              //child process
write(fd[1],&writeNum,sizeof(int));
printf("Parent writes: %s and %d\n",writeMessege,writeNum);
}
else{
read(fd[0],readMessege,sizeof(readMessege));
read(fd[0],&readNum,sizeof(int));                            //parent process  
printf("Child reads: %s and %d\n",readMessege,readNum);
}
return 0;
}

