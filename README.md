# PRESENT-table-lookup

The PRESENT block cipher is a 64-bit block cipher that operates with
80- or 128-bit keys. It is a lightweight block cipher that uses the SPN
structure and accommodates lower security levels and complexity
compared to other block ciphers like AES. This project implements
the encryption process of the PRESENT cipher with 80-bit key.
• The PRESENT block cipher consists of three layers in each round:
–Round key mixing
–Substitution
–Permutation
• This cipher consists of 31 rounds.


The mission of this project is to conduct cryptanalysis of the PRESENT block
cipher. This is done through the following processes:
• Implementation of the PRESENT block cipher encryption with a 64-bit
plaintext and 80-bit key in Table lookup Approach
• Implementation of the Time-Memory Tradeoff Attack on a reduced key
version of the PRESENT cipher.
• For the TMTO attack, the 80-bit key is reduced to 20-bit version by
ANDing the hexadecimal value 0xFFFFF to the 80-bit key which
returns the rightmost 20 bits of the 80-bit key used.
