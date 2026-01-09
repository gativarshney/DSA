int setRightMostbit(int n){
    return n | n+1;
}
// n = 1011 (11)
// n + 1 = 1100 (12)
// n | (n+1) = 1111 (15)


//* NOTE
//! Set the rightmost unset bit: turn that 0 into 1 → n | (n + 1)
//! Unset the rightmost set bit: turn the rightmost 1 into 0 → n & (n - 1)