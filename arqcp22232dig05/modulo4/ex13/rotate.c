int rotate_left(int num, int nbits) {
    unsigned int tmp = num;      // 1101
    tmp >>= 32-nbits;   // 0001
    num <<= nbits;      // 1010
    return tmp + num;
}

int rotate_right(int num, int nbits) {
    unsigned int unum = (unsigned int) num; // force logical right shift by using an unsigned value
    int tmp = unum;     // 1101
    tmp <<= 32-nbits;   // 1000
    unum >>= nbits;     // 0110
    return tmp + unum;
}

