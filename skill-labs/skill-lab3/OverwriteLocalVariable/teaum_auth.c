#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

int authentication(char *magicword) { 
	bool flag = 0;
	char buffer[16];
	strcpy(buffer, magicword);
	if(strcmp(buffer, "cyberlionsftw") == 0) 
		flag = 1;
	if(strcmp(buffer, "gocyberlions") == 0) 
		flag = 1;
	return flag; 
}

int main(int argc, char *argv[]) { 
	bool auth_token = authentication (argv[1]);
	if(auth_token == 1) { 
		printf("\n ##########\n"); 
		printf(" Welcome to the team! \n"); 
		printf(" ##########\n");
	} else {
		printf("\n You're not a true fanboy! \n");
	}
}
