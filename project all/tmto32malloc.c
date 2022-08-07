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
    int t = 1626;
    int m = 1626;
    uint64_t plain[1] = {0x0};
    //uint64_t k[t][m];
    //uint64_t startkey[t][m];
    //uint64_t **startkey;
    //startkey = (uint64_t**)malloc(sizeof(uint64_t *) * t + sizeof(uint64_t) * m * t);
    uint64_t** startkey = (uint64_t**)malloc(m * sizeof(uint64_t*));
    for (int i = 0; i < t; i++)
        startkey[i] = (uint64_t*)malloc(t * sizeof(uint64_t));
        uint64_t** endkey = (uint64_t**)malloc(m * sizeof(uint64_t*));
    for (int i = 0; i < t; i++)
        endkey[i] = (uint64_t*)malloc(t * sizeof(uint64_t));
        //uint64_t endkey[t][m];
        //uint64_t prevkey[t][m];
        uint64_t** y = (uint64_t**)malloc(m * sizeof(uint64_t*));
    for (int i = 0; i < t; i++)
        y[i] = (uint64_t*)malloc(t * sizeof(uint64_t));
        //uint64_t y[t][m];
        int a =137;
	//("\nEnter plaintext:\n");
	//scanf("%" SCNx64 , plain); //taking plaintext as input
	for(int l = 0; l< t; l++){
	for(int j = 0; j < m; j++){
            srand (rand()+ (j+l*j)); //generate random seed to generate random starting keys/ key zeros]
        startkey[l][j] = printRandoms(); //generating random key zeros/ starting keys
        endkey[l][j] = printendkey(plain[0], startkey[l][j], (l+1)); //calculating end keys
        }
	bubbleSort(endkey[l], startkey[l], m); //Sorting the end keys
	}

	//ONLINE phase
	//-----------*********-------------------

	uint64_t cipher[1];
	printf("\nEnter ciphertext:\n");
	scanf("%" SCNx64 , cipher); //taking known ciphertext as input
	uint64_t** R = (uint64_t**)malloc(m * sizeof(uint64_t*));
    for (int i = 0; i < t; i++)
        R[i] = (uint64_t*)malloc(t * sizeof(uint64_t));
	//uint64_t R[t][t];
	uint64_t ciphertext[t];
uint64_t plaintext[1];
int count = 0;
	for(int l = 0; l<t; l++){
            ciphertext[0] = cipher[0];
    for(int o = 0; o < t; o++){
            R[l][o] = (((a*ciphertext[o]) + (l+1)) & 0x00000000FFFFFFFF); //Generating a key by using chaining function of the ciphertext
            for(int r =0; r<t; r++){
                    for(int j = 0; j < m; j++){
                        if(R[l][o] == endkey[r][j]){ //checking if the key matches any end key in any of the subtables
                count++;
                //printf("%llx\n", R[l][o]); //Matched end key:
                //printf("%d\n", l+1); //Subtable number:
                uint64_t mkey[t];
                mkey[0] = startkey[r][j]; //finding the key zero of the matched end key
                uint64_t z[t];
            for(int i = 0; i < t; i++){
                        uint64_t p[1];
                p[0] = plain[0];
                uint64_t newkey[2] = {0x0, mkey[i]}; //80 bit key taken as 2 words (where a word is 64 bit).
	            z[i] = Present_encrypt(p, newkey); //generating ciphertexts for all the keys in the chain of the matched end key
                if(z[i] == cipher[0]){ //checking if generated ciphertext matches the known ciphertext
                    printf("This is the key: %llx\n", mkey[i]); //if it matches the key used to generate that ciphertext is the unknown key
                //printf("Subtable number: %d\n", l+1); //key found in this subtable
                }
                mkey[i+1] = (((a*z[i]) + (l+1)) & 0x00000000FFFFFFFF); //generating all keys in the chain
            }
        }
}
        }
        plaintext[0] = plain[0];
        uint64_t keyupdate[2] = {0x0, R[l][o]};//80 bit key taken as 2 words (where a word is 64 bit).
        ciphertext[o+1] = Present_encrypt(plaintext, keyupdate); //when there's no match in end key, update R[l].
	}

	}
printf("Total number of matched keys: %d", count);
    return 0;
}

