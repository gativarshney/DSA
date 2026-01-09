// Given two positive integer n and  k, check if the kth index bit of n is set or not.
// Note: A bit is called set if it is 1. 


//* Using left shift

bool checkKthBit(int n, int k) {
    if((n & (1 << k)) == 1) return true;
    return false;
}

//* Using right shift

bool checkKthBit(int n, int k) {
    if((n >> k) & 1 == 1) return true;
    return false;
}