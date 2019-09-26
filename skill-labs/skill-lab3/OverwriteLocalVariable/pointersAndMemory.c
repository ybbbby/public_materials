#include <stdio.h>
#include <stdlib.h>

int main(){

	int array[3]={1,2,3};
	int *ptr = array;

	printf("%x \n", ptr);

	printf("%x \n", (int*) ((char*) ptr+1)); 

	printf("%x \n", *ptr);

	printf("%x \n", *((int*) ((char*) ptr+1))); 
			
}
