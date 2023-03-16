#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>


int main(){

pid_t pid_A, pid_B, pid_M, pid_C;
int status, m, buffer, fd;


pid_B = fork();
if(pid_B==0){
	printf("Mi pid es: %d\n", getpid());
	printf("El pid de mi padre es: %d\n", getppid());
	execl("procesoB","",NULL);
	return 3;
	
	}	
		
pid_C = fork();
if(pid_C==0){
	sleep(3);
	printf("Mi pid es: %d\n", getpid());
	printf("El pid de mi padre es: %d\n", getppid());
	return 0;
	
	}
	
waitpid(pid_B, &status, 0);
if (WIFEXITED(status)){
	printf("El valor de retorno de B es: %d\n",WEXITSTATUS(status));
	fd=open("enteros.txt",0);
	for(int i = 0; i <= 1000; i++){
	m = read (fd, &buffer, sizeof(int));
	printf("%d",buffer);
	}
	close(fd);	
}
return 0;
	
	}
