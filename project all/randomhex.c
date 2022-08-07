#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

typedef unsigned long long uint64_t;

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

int main(){
uint64_t startkey[256];
for(int i = 0; i<256; i++){
srand (rand()+i);
startkey[0] = printRandoms() +0x100000 + rand(); //generating random key zeros/ starting keys
        printf("key: %llx\n", startkey[0]);
}
return 0;
}
