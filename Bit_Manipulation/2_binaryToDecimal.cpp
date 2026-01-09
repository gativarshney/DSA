int binaryToDecimal(string &b) {
    int len = b.length();
    int ans = 0, power = 1;
    for(int i=len-1; i>=0; i--){
        if(b[i] == '1'){
            ans += power;
        }
        power *= 2;
    }
    return ans;
}