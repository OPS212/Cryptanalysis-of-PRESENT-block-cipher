// C program for generating a
// random number in a given range.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "sbox.h"
#include "lookup_encrypt.h"
#include "tmto.h"

typedef unsigned long long uint64_t;

// Driver code
int main()
{
    //Preprocessing phase
    //---------****------------
    int t = 101;
    int m = 102;

    //printf("%05llx ", k[0]);

    uint64_t plain[1];
    uint64_t k[m][t];
    uint64_t skey[m][t];
        uint64_t ekey[m][t];
        uint64_t y[m][t];
        int a =137;
	 //80 bit key taken as 2 words (where a word is 64 bit), the key used here is 0xk0.
	printf("\nEnter plaintext:\n");
	scanf("%" SCNx64 , plain); //taking plaintext as input

	 for(int j = 0; j<m; j++){
            k[j][0] = 0x37c0;
        for(int i = 0; i < t; i++){
                uint64_t p[1];
        p[0] = plain[0];
                 uint64_t key[2] = {0x0, k[j][i]};
     //printf("Plaintext is: %016llx \n", p[0]);
        y[j][i] = Present_encrypt(p, key);
        //printf("This is the key: %llx\n", k[i]);
        k[j][i+1] = (((a*y[j][i]) + j) & 0x00000000000FFFFF);
        }
        printf("This is the last key: %llx for m = %d\n", k[j][t], m);
	 }

	}
