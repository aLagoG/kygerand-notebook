int pow(int x, unsigned int y, int m) {
    int res = 1;
    x %= m;
    while (y) {
        if (y & 1) {
            res = (res * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return res;
}