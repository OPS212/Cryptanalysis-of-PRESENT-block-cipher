#ifndef TMTO32BIT_H_INCLUDED
#define TMTO32BIT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "sbox.h"
#include "lookup_encrypt.h"

typedef unsigned long long uint64_t;

uint64_t printendkey(uint64_t x, uint64_t k, int b)
{
    //printf("Plaintext is: %016llx\n", x);
        uint64_t y[256];
    uint64_t ks[256];
        ks[0] = k;
    for(int i = 0; i<256; i++){
            uint64_t plain[1];
    plain[0] = x;
    uint64_t key[2] = {0x0, ks[i]};
    int a =137;
    y[i] = Present_encrypt(plain, key);
    ks[i+1] = (((a*y[i]) + b) & 0x00000000FFFFFFFF);
    //printf("Next key is: %llx\n", ks[i+1]); //
}
return ks[255];
}
// Generates and prints 'count' random
// numbers in range [lower, upper].
uint64_t printRandoms()
{
    uint64_t lower= 0x0;
    uint64_t upper= 0xFFFFFFFF;
    int count= 1;
    int i;
    uint64_t num;
    for (i = 0; i < count; i++) {
        num = (rand() %
        (upper - lower + 1)) + lower;
    }
    return num;
}


void swap(uint64_t* xp, uint64_t* yp)
{
    uint64_t temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(uint64_t arr[], uint64_t p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
}

/* Function to print an array */
void printArray(uint64_t arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%lx ", arr[i]);
    printf("\n");
}


#endif // TMTO32BIT_H_INCLUDED
