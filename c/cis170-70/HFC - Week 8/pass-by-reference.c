#include <stdio.h>

void cubeByReference(int *nPtr);

int main (void) {
    int number = 5;

    printf("The original value of number is %d\n", number);
    
    cubeByReference(&number);

    printf("The new value of number is %d\n", number);
}

// This function accepts as an argument an address, which is a pointer, I then derefence this address uising *, to get the value at the address and assign it to the value at that address cubed
void cubeByReference(int *nPtr) {
    *nPtr =  *nPtr * *nPtr * *nPtr;
}