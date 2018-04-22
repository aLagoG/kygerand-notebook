int pow(int x, unsigned int y) {
    int res = 1;
    while (y) {
        if (y & 1) {
            res *= x;
        }
        y >>= 1;
        x *= x;
    }
    return res;
}