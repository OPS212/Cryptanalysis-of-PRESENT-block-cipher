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
    int m = 101;

    //printf("%05llx ", k[0]);

    uint64_t plain[1];
    uint64_t k[t][m];
    uint64_t startkey[t][m];
        uint64_t endkey[t][m];
        uint64_t prevkey[t][m];
        uint64_t y[t][m];
        int a =137;
	 //80 bit key taken as 2 words (where a word is 64 bit), the key used here is 0xk0.
	printf("\nEnter plaintext:\n");
	scanf("%" SCNx64 , plain); //taking plaintext as input
	for(int l = 0; l< t; l++){
	for(int j = 0; j < m; j++){
            srand (rand()+ (j+l*j)); //generate the same seed to check for debugging [done] [add+(time(0))]
        startkey[l][j] = printRandoms();
        //printf("key zero is: %llx\n", startkey[l][j]); //key zero is:
        endkey[l][j] = printendkey(plain[0], startkey[l][j], (l+1));
        //printf("end key is: %llx\n", endkey[l][j]); //End key is:


        //printf("Sorted array: \n");

	}
	//printArray(startkey[l], m);
	//printf("\n");
	bubbleSort(endkey[l], startkey[l], m);
	//printf("Endkeys: \n");
        //printArray(endkey[l], m);
        //printf("Startkeys: \n");
        //printArray(startkey[l], m);
        //
	}

	/*for(int l = 0; l< t; l++){
	for(int n = 0; n < m; n++){
        printf("end key: %llx\n", ekey[l][n]);
        printf("\n");
        }
	}*/

	//ONLINE phase
	//-----------*********-------------------

	uint64_t cipher[1];
	printf("\nEnter ciphertext:\n");
	scanf("%" SCNx64 , cipher); //taking plaintext as input
	uint64_t R[t][t];
	uint64_t ciphertext[t];
uint64_t plaintext[1];
	for(int l = 0; l<t; l++){
            ciphertext[0] = cipher[0];



            //printf("chaining key: %llx\n", R[l]);
    for(int o = 0; o < t; o++){
            R[l][o] = (((a*ciphertext[o]) + (l+1)) & 0x00000000000FFFFF);
            //printf("New key is: %llx\n", R[l][o]);
        for(int r =0; r<t; r++){

        for(int j = 0; j < m; j++){


                //printf("key: %llx\n", endkey[r][j]);
            if(R[l][o] == endkey[r][j]){
                printf("matched key: %llx\n", R[l][o]);
                uint64_t mkey[t];
                mkey[0] = startkey[r][j];
                //printf("New key zero: %llx\n", mkey[0]);
                uint64_t z[t];

                //printf("plaintext: %016llx\n", p[0]);
                for(int i = 0; i < t; i++){
                        uint64_t p[1];
                p[0] = plain[0];
                //printf("plaintext: %llx\n", p[0]);
                 uint64_t newkey[2] = {0x0, mkey[i]};
                // printf("This is the new key: %04lx%016lx for subtable = %d\n", newkey[0], newkey[1], l+1);
                 z[i] = Present_encrypt(p, newkey);
                 //printf("This is the new ciphertext: %016lx\n", z[i]);
                 if(z[i] == cipher[0]){
                    printf("This is the key: %llx\n", mkey[i]);
                printf("Subtable number: %d\n", l+1);
                    //break;
                 }
                 //else if(z[i] != R[l]){
                 mkey[i+1] = (((a*z[i]) + (l+1)) & 0x00000000000FFFFF);
                 //printf("Subtable number: %d\n", l+1);
                 //continue;
                 //}
        }
        //break;
            }
            //else if(R[l] != endkey[o][j]){
              //  printf("No match\n");
                /*
                    uint64_t plaintext[1];
                plaintext[0] = ciphertext[0];
            uint64_t keyupdate[2] = {0x0, R[l]};
                ciphertext[0] = Present_encrypt(plaintext, keyupdate);*/
            //}

        }
        }

                plaintext[0] = plain[0];
                //printf("New plaintext is: %llx\n", plaintext[0]);
                //printf("New key is: %llx\n", R[l][o]);
            uint64_t keyupdate[2] = {0x0, R[l][o]};
	ciphertext[o+1] = Present_encrypt(plaintext, keyupdate);
	//printf("ciphertext: %llx\n", ciphertext[o+1]);
	}

	}

    return 0;
}

/*
Wrong key generation:

printf("key zero is: %llx\n", k[l][0]);

        for(int i = 0; i < t; i++){
                uint64_t pla[1];
            pla[0] = plain[0];
                 uint64_t key[2] = {0x0, k[l][i]};
                 printf("Plaintext is: %016llx \n\n", pla[0]);
        y[l][i] = Present_encrypt(pla, key);
        printf("key begin: %llx for k[%d][%d]\n", k[l][i], l, i);
        k[l][i+1] = (((a*y[l][i]) + (l+1)) & 0x00000000000FFFFF);
        printf("key update: %llx for k[%d][%d]\n", k[l][i+1], l, i+1);
        }
        skey[l][j] = k[l][0];
        printf("start key: %llx\n", skey[l][j]);
        prevkey[l][j] = k[l][100];
        //printf("%llx\n", prevkey[l][j]);
        ekey[l][j] = k[l][101];
        printf("end key: %llx\n", ekey[l][j]);

        */
