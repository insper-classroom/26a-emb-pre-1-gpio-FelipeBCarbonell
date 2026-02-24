#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    return x * y;
}

int main(void) {
    int a, b = 5; //uninitvar, legacyUninitvar
    int result = multiplyNumbers(a, b);

    printf("Result of %d * %d: %d\n", a, b, result);

    int arr[NUM_ELEMENTS];
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = i * result;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
