int powerOf2(int n) {
    if(n == 0) return 1;
    return 2 * powerOf2(n-1);
}