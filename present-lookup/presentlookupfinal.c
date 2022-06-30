#include <stdio.h>
#include <inttypes.h>
#include "sbox.h"
typedef unsigned long long uint64_t;

int main() {
    int r; //current round number
    int R = 32; //total number of rounds
    uint64_t roundkey[R]; // generated round keys
    uint64_t key[2] = {0xffff, 0xffffffffffffffff}; //80 bit key taken as 2 words (where a word is 64 bit), the key used here is 0xffffffffffffffffffff.
    for (r = 0; r < R; r++) { //updating round keys
	roundkey[r] = ((key[0] << 48) & 0xFFFF000000000000) ^ ((key[1] >> 16) & 0x0000FFFFFFFFFFFF); //64 bit round key in round r.
	uint64_t temp[1];
	temp[0] = key[0]; // rotate key left by 61 bits
	key[0] = ((key[1] >> 3) & 0x000000000000FFFF);
    key[1] = ((temp[0] << 45) & 0x1FFFE00000000000) ^ ((key[1] << 61) & 0xE000000000000000) ^ ((key[1] >> 19) & 0x00001FFFFFFFFFFF);
    key[0] = ((sbox[(key[0] >> 12) & 0xF] << 12) & 0xF000) ^ (key[0] & 0x0FFF); // leftmost 4 bits through s-box
    key[1] = (((r+1) << 15) & 0xF8000) ^ key[1];  // add round count
    }
	uint64_t plain[1];
	uint64_t data[16];
	printf("Enter plaintext:\n");
	scanf("%" SCNx64 , plain); //taking plaintext as input
	for(int i = 0; i<31; i++){ //encryption process
    plain[0] = plain[0] ^ roundkey[i]; //add round key
	data[0] = ((plain[0] >> 0) & 0x0F); //bit 0-3 (rightmost 4bits)
	data[0] = sbox16[data[0]]; //spbox of bit 0-3
	data[1] = ((plain[0] >> 4) & 0x0F);//bit 4-7
	data[1] = sbox15[data[1]];//spbox of bit 4-7
	data[2] = ((plain[0] >> 8) & 0x0F);//bit 8-11
	data[2] = sbox14[data[2]];//spbox of bit 8-11
	data[3] = ((plain[0] >> 12) & 0x0F); //bit 12-15
	data[3] = sbox13[data[3]]; //spbox of bit 12-15
	data[4] = ((plain[0] >> 16) & 0x0F); //bit 16-19
	data[4] = sbox12[data[4]];//spbox of bit 16-19
	data[5] = ((plain[0] >> 20) & 0x0F); //bit 20-23
	data[5] = sbox11[data[5]]; //spbox of bit 20-23
	data[6] = ((plain[0] >> 24) & 0x0F); //bit 24-27
	data[6] = sbox10[data[6]]; //spbox of bit 24-27
	data[7] = ((plain[0] >> 28) & 0x0F); //bit 28-31
	data[7] = sbox9[data[7]];//spbox of bit 28-31
	data[8] = ((plain[0] >> 32) & 0x0F); //bit 32-35
	data[8] = sbox8[data[8]];//spbox of bit 32-35
	data[9] = ((plain[0] >> 36) & 0x0F); //bit 36-39
	data[9] = sbox7[data[9]];//spbox of bit 36-39
	data[10] = ((plain[0] >> 40) & 0x0F); //bit 40-43
	data[10] = sbox6[data[10]];//spbox of bit 40-43
	data[11] = ((plain[0] >> 44) & 0x0F); //bit 44-47
	data[11] = sbox5[data[11]];//spbox of bit 44-47
	data[12] = ((plain[0] >> 48) & 0x0F); //bit 48-51
	data[12] = sbox4[data[12]];//spbox of bit 48-51
	data[13] = ((plain[0] >> 52) & 0x0F); //bit 52-55
	data[13] = sbox3[data[13]];//spbox of bit 52-55
	data[14] = ((plain[0] >> 56) & 0x0F); //bit 56-59
	data[14] = sbox2[data[14]];//spbox of bit 56-59
	data[15] = ((plain[0] >> 60) & 0x0F); //bit 60-63
	data[15] = sbox1[data[15]];//spbox of bit 60-63
	plain[0] = data[0] ^ data[1] ^ data[2] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[11] ^ data[12] ^ data[13] ^ data[14] ^ data[15]; //XOR all spbox output
	}
	plain[0] = plain[0] ^ roundkey[31]; //add last round key
	printf("Ciphertext:\n%016llx\n\n"  , plain[0]); //Print ciphertext
	return 0;
}




