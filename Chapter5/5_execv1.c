#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
char command[256], *argv[32];
	argv[0]= "/bin/ls";
	argv[1]=NULL;
    execv(argv[0], argv);
	//execl(argv[0],argv[0],NULL);
    return 0;
}
