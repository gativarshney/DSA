int clearIthBit(int n, int i){
    if(n & (1 << i)){
        return n & (~(1 << i));
    }
    return n;
}