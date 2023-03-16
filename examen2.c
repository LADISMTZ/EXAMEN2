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

pid_t pid_D, pid_E, pid_F;
int status;

pid_D = fork();
if(pid_D==0){
	return 2;
	
	}	
		
pid_F = fork();	
if(pid_F==0){
	return 13;
	}

pid_E = fork();	
if(pid_E==0){
	return 14;
	
	}

float res;
waitpid(pid_D, &status, 0);
res=((float)WEXITSTATUS(status)*2.0)-1.0;
waitpid(pid_F, &status, 0);
res=res+((float)WEXITSTATUS(status)/1000);
waitpid(pid_E, &status, 0);
res=res+(((float)WEXITSTATUS(status)+3.0)/1000.0);
printf ("El valor de res es: %f", res);
return 0;

}



	
