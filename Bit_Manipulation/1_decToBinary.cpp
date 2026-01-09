string decToBinary(int n) {
    string ans = "";
    while(n != 1){
        if(n % 2 == 1) ans += "1";
        else ans += "0";
        n = n / 2;
    }
    ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}