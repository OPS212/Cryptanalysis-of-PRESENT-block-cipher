#include <stdio.h>
#include <inttypes.h>
#include "sbox.h"
typedef unsigned long long uint64_t;

int main() {
	uint64_t plain[1];
	uint64_t data[16];
	printf("\nEnter HEX:\n");
	scanf("%" SCNx64 , plain);
	data[0] = ((plain[0] >> 0) & 0x0F);
	printf("%016llx\n"  , data[0]);
	data[0] = sbox16[data[0]];
	printf("%016llx\n"  , data[0]);
	data[1] = ((plain[0] >> 4) & 0x0F);
	printf("%016llx\n" , data[1]);
	data[2] = ((plain[0] >> 8) & 0x0F);
	printf("%016llx\n" , data[2]);
	data[3] = ((plain[0] >> 12) & 0x0F);
	printf("%016llx\n" , data[3]);
	data[4] = ((plain[0] >> 16) & 0x0F);
	printf("%016llx\n" , data[4]);
	data[5] = ((plain[0] >> 20) & 0x0F);
	printf("%016llx\n" , data[5]);
	data[6] = ((plain[0] >> 24) & 0x0F);
	printf("%016llx\n" , data[6]);
	data[7] = ((plain[0] >> 28) & 0x0F);
	printf("%016llx\n" , data[7]);
	data[8] = ((plain[0] >> 32) & 0x0F);
	printf("%016llx\n" , data[8]);
	data[9] = ((plain[0] >> 36) & 0x0F);
	printf("%016llx\n" , data[9]);
	data[10] = ((plain[0] >> 40) & 0x0F);
	printf("%016llx\n" , data[10]);
	data[11] = ((plain[0] >> 44) & 0x0F);
	printf("%016llx\n" , data[11]);
	data[12] = ((plain[0] >> 48) & 0x0F);
	printf("%016llx\n" , data[12]);
	data[13] = ((plain[0] >> 52) & 0x0F);
	printf("%016llx\n" , data[13]);
	data[14] = ((plain[0] >> 56) & 0x0F);
	printf("%016llx\n" , data[14]);
	data[15] = ((plain[0] >> 60) & 0x0F);
	printf("%016llx\n" , data[15]);
	return 0;
}

