#include <stdio.h>
#include <inttypes.h>

//typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
//typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

uint8_t sbox[16] = {
	0x0C,0x05,0x06,0x0B,
	0x09,0x00,0x0A,0x0D,
	0x03,0x0E,0x0F,0x08,
	0x04,0x07,0x01,0x02
};


int main() {
    int r;
    int R = 32;
    uint64_t subkey64[R];
    uint64_t key[2] = {0x0, 0x0};
    for (r = 0; r <= R; r++){
    //uint64_t data[16];
	//printf("%016llx"  , key[0]);
	//printf("%04llx"  , key[1]);
	subkey64[r] = ((key[0] << 48) & 0xFFFF000000000000) ^ ((key[1] >> 16) & 0x0000FFFFFFFFFFFF);
	//printf("%016llx"  , subkey64[0]);
	uint64_t temp[1];
	temp[0] = key[0];
	//printf("%016llx"  , temp[0]);
	key[0] = ((key[1] >> 3) & 0x000000000000FFFF);
    key[1] = ((temp[0] << 45) & 0x1FFFE00000000000) ^ ((key[1] << 61) & 0xE000000000000000) ^ ((key[1] >> 19) & 0x00001FFFFFFFFFFF);
    key[0] = ((sbox[(key[0] >> 12) & 0xF] << 12) & 0xF000) ^ (key[0] & 0x0FFF);
    key[1] = (((r+1) << 15) & 0xF8000) ^ key[1];
    printf("%016llx"  , key[0]);
	printf("%04llx\n"  , key[1]);
    //printf("1st round key = %4lx%16lx\n", key[0], key[1]);
}
	return 0;
}
