#include <stdio.h>
#include <inttypes.h>
#include "sbox.h"
#include "keyzero.h"
typedef unsigned long long uint64_t;

int main() {
	uint64_t plain[1];
	uint64_t data[16];
	printf("Enter HEX:\n");
	scanf("%" SCNx64 , plain);
	for(int i = 0; i<31; i++){
    plain[0] = plain[0] ^ key [i];
	data[0] = ((plain[0] >> 0) & 0x0F);
	//printf("%016llx\n"  , data[0]);
	data[0] = sbox16[data[0]];
	//printf("%016llx\n\n"  , data[0]);
	data[1] = ((plain[0] >> 4) & 0x0F);
	//printf("%016llx\n" , data[1]);
	data[1] = sbox15[data[1]];
	//printf("%016llx\n\n"  , data[1]);
	data[2] = ((plain[0] >> 8) & 0x0F);
	//printf("%016llx\n" , data[2]);
	data[2] = sbox14[data[2]];
	//printf("%016llx\n\n"  , data[2]);
	data[3] = ((plain[0] >> 12) & 0x0F);
	//printf("%016llx\n" , data[3]);
	data[3] = sbox13[data[3]];
	//printf("%016llx\n\n"  , data[3]);
	data[4] = ((plain[0] >> 16) & 0x0F);
	//printf("%016llx\n" , data[4]);
	data[4] = sbox12[data[4]];
	//printf("%016llx\n\n"  , data[4]);
	data[5] = ((plain[0] >> 20) & 0x0F);
	//printf("%016llx\n" , data[5]);
	data[5] = sbox11[data[5]];
	//printf("%016llx\n\n"  , data[5]);
	data[6] = ((plain[0] >> 24) & 0x0F);
	//printf("%016llx\n" , data[6]);
	data[6] = sbox10[data[6]];
	//printf("%016llx\n\n"  , data[6]);
	data[7] = ((plain[0] >> 28) & 0x0F);
	//printf("%016llx\n" , data[7]);
	data[7] = sbox9[data[7]];
	//printf("%016llx\n\n"  , data[7]);
	data[8] = ((plain[0] >> 32) & 0x0F);
	//printf("%016llx\n" , data[8]);
	data[8] = sbox8[data[8]];
	//printf("%016llx\n\n"  , data[8]);
	data[9] = ((plain[0] >> 36) & 0x0F);
	//printf("%016llx\n" , data[9]);
	data[9] = sbox7[data[9]];
	//printf("%016llx\n\n"  , data[9]);
	data[10] = ((plain[0] >> 40) & 0x0F);
	//printf("%016llx\n" , data[10]);
	data[10] = sbox6[data[10]];
	//printf("%016llx\n\n"  , data[10]);
	data[11] = ((plain[0] >> 44) & 0x0F);
	//printf("%016llx\n" , data[11]);
	data[11] = sbox5[data[11]];
	//printf("%016llx\n\n"  , data[11]);
	data[12] = ((plain[0] >> 48) & 0x0F);
	//printf("%016llx\n" , data[12]);
	data[12] = sbox4[data[12]];
	//printf("%016llx\n\n"  , data[12]);
	data[13] = ((plain[0] >> 52) & 0x0F);
	//printf("%016llx\n" , data[13]);
	data[13] = sbox3[data[13]];
	//printf("%016llx\n\n"  , data[13]);
	data[14] = ((plain[0] >> 56) & 0x0F);
	//printf("%016llx\n" , data[14]);
	data[14] = sbox2[data[14]];
	//printf("%016llx\n\n"  , data[14]);
	data[15] = ((plain[0] >> 60) & 0x0F);
	//printf("%016llx\n" , data[15]);
	data[15] = sbox1[data[15]];
	//printf("%016llx\n\n"  , data[15]);
	plain[0] = data[0] ^ data[1] ^ data[2] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[11] ^ data[12] ^ data[13] ^ data[14] ^ data[15];
	}
	plain[0] = plain[0] ^ key[31];
	printf("%016llx\n\n"  , plain[0]);
	return 0;
}



