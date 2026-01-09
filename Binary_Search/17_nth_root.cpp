//* Find the Nth root of a number using binary search


//! Brute Force Method
// Power exponential method: to find m^n
long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}
int NthRoot(int n, int m) {
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) {
        long long val = func(i, n);
        if (val == m * 1ll) return i;
        else if (val > m * 1ll) break;
    }
    return -1;
}
// Time complexity:is O(m^1/n X logn) (because of break power of m is 1/n)
// Space Complexity: O(1)

//! Optimized Solution (Fail for 10^9)

// Power exponential method: to find m^n
long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}
int nthRoot_Optimised(int m, int n){
    int low = 1, high = m;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(func(mid, n) == m) return mid;
        else if(func(mid, n) > m) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
// TC : O(logm X logn) but fails for 10^9...

//! Most Optimal Solution
// return 1 if == m
// return 0 if < m
// return 2 if > m
int func(int mid, int n, int m){
    long long int ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int nthRoot_Optimal(int m, int n){
    int low = 1, high = m;
    while(low <= high){
        int mid = low + (high - low)/2;
        int val = func(mid, n, m);
        if(val == 1) return mid;
        else if(val == 0) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

// Time Complexity: O(nlogm)