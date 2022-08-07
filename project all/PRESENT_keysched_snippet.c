// Code snippet to compute round keys for PRESENT:
// Some things come from outside such as
//     R is a global variable representing the number of rounds (can be replaced by constant)
//     PRINT_KEYSCHED is a constant of value 0 (no print) or 1 (print) defined externally
//     key_reg[] is a 2 word (where a word is 64 bit) representation of the 80-bit key register
//        (It is initialized to the original 80-bit key.)
//     subkey[] array stores the generated round keys
//     sbox[] is the 16 nibble PRESENT S-box table


// derive RK 1 to RK R+1
void key_schedule(unsigned long key_reg[])
{
  // key_reg[0] holds leftmost 16 bits, key_reg[1] holds rightmost 64 bits
  int r;
  int R = 32;
  int PRINT_KEYSCHED = 1;
  unsigned long temp;

  for (r = 0; r <= R; r++) {   // R is total number of rounds, can be hardcoded
    if (PRINT_KEYSCHED)
      printf("\nRound %d: key_reg = %4lx / %16lx\n", r, key_reg[0], key_reg[1]);
    // leftmost 16 bits of key_reg is RK
    unsigned long subkey64[r] = ((key_reg[0] << 48) & 0xFFFF000000000000)
                   ^ ((key_reg[1] >> 16) & 0x0000FFFFFFFFFFFF);
    if (PRINT_KEYSCHED) printf("subkey64[%d] = %16lx\n", r, subkey64[r]);

    // rotate key_reg left by 61 bits
    temp = key_reg[0];
    key_reg[0] = ((key_reg[1] >> 3) & 0x000000000000FFFF);
    key_reg[1] = ((temp << 45) & 0x1FFFE00000000000)
                  ^ ((key_reg[1] << 61) & 0xE000000000000000)
                  ^ ((key_reg[1] >> 19) & 0x00001FFFFFFFFFFF);
    if (PRINT_KEYSCHED)
      printf("Rotate 61 left: key_reg = %4lx / %16lx\n", key_reg[0], key_reg[1]);

    // leftmost 4 bits through s-box
    key_reg[0] = ((sbox[(key_reg[0] >> 12) & 0xF] << 12) & 0xF000)
                  ^ (key_reg[0] & 0x0FFF);
    if (PRINT_KEYSCHED)
      printf("S-box on 4 bits: key_reg = %4lx / %16lx\n", key_reg[0], key_reg[1]);

    // add round count
    key_reg[1] = (((r+1) << 15) & 0xF8000) ^ key_reg[1];
    if (PRINT_KEYSCHED)
      printf("XOR round counter: key_reg = %4lx / %16lx\n", key_reg[0], key_reg[1]);
  }
}

