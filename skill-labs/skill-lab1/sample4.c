#include <stdio.h>

int main(){
    int pos = 0;
    char *text = "Hello World";

    printf("Hello World!\n");
    printf("Which letter do you want? ");
    scanf("%d",  &pos);
    printf("%c\n", *(text+pos));
}