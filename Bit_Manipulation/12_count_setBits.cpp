// Brian Kernighan’s Algorithm
int setBits(int n) {
    int cnt = 0;
    while(n != 0){
        n = n & n-1;
        cnt++;
    }
    return cnt;
}
//? TC: O(number of set bits in n)


// Bitwise Shift Method
int setBits_I(int n) {
    int cnt = 0;
    while(n > 0){
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
// ? TC:  O(number of bits in n) = O(logn)

int countSetBit(int n){
    int cnt = 0;
    while(n > 0){
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    if(n == 1) cnt++;
    return cnt;
}
// ? TC: O(logn)