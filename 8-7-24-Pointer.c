#include <stdio.h>

void displayPoint(char *ptr);
char playPoint(char *ptr);




int main(){
    char  Point = 'A';
    
    char *ptr = &Point;
    
    printf("I am at point: %c\n", *ptr); // Point A
    
    displayPoint(ptr);
    
    printf("I am at point: %c\n", *ptr); 
    
    playPoint(ptr);
    printf("I am at point: %c\n", *ptr); 
}

void displayPoint(char *ptr){ // Point B increment by 1 in reference to ASCII
    (*ptr)++;
}


char playPoint(char *ptr){ // Point C
    return (*ptr)++;
}










