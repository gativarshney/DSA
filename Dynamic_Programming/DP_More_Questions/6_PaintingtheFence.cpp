//! Recursion
class Solution {
private:
    int add(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) + (b % mod)) % mod;
    }
    int mul(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) * (b % mod)) % mod;
    }
    int solve(int idx, int k){
        if(idx == 1) return k;
        if(idx == 2) return add(k, mul(k, k-1));
        int a = mul(solve(idx-2, k), (k-1));
        int b = mul(solve(idx-1, k), (k-1));
        return add(a, b);
    }
public:
    int countWays(int n, int k){
        return solve(n, k);
    }
};
// Time Complexity: O(2^n) where n is the number of posts.
// Space Complexity: O(n) for the recursion stack.

//! Memoization
class Solution {
private:
    int add(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) + (b % mod)) % mod;
    }
    int mul(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) * (b % mod)) % mod;
    }
    int solve(int idx, int k, vector<int> &dp){
        if(idx == 1) return k;
        if(idx == 2) return add(k, mul(k, k-1));
        if(dp[idx] != -1) return dp[idx];
        int a = mul(solve(idx-2, k, dp), (k-1));
        int b = mul(solve(idx-1, k, dp), (k-1));
        return dp[idx] = add(a, b);
    }
public:
    int countWays(int n, int k){
        vector<int> dp(n+1, -1);
        return solve(n, k, dp);
    }
};
// Time Complexity: O(n) where n is the number of posts.
// Space Complexity: O(n) for the recursion stack and O(n) for the dp array.

//! Tabulation
class Solution {
private:
    int add(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) + (b % mod)) % mod;
    }
    int mul(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) * (b % mod)) % mod;
    }
public:
    int countWays(int n, int k){
        vector<int> dp(n+1, 0);
        dp[1] = k;
        dp[2] = k * k;
        for(int idx = 3; idx<=n; idx++){
            int a = mul(dp[idx-2], (k-1));
            int b = mul(dp[idx-1], (k-1));
            dp[idx] = add(a, b);
        }
        return dp[n];
    }
};
// Time Complexity: O(n) where n is the number of posts.
// Space Complexity: O(n) for the dp array.

//! Space Optimization
class Solution {
private:
    int add(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) + (b % mod)) % mod;
    }
    int mul(int a, int b){
        int mod = 1e9 + 7;
        return ((a % mod) * (b % mod)) % mod;
    }
public:
    int countWays(int n, int k){
        if (n == 1) return k;
        if (n == 2) return mul(k, k);
        int prev2 = k;
        int prev1 = k * k;
        for(int idx = 3; idx<=n; idx++){
            int a = mul(prev2, (k-1));
            int b = mul(prev1, (k-1));
            int curr = add(a, b);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// Time Complexity: O(n) where n is the number of posts.
// Space Complexity: O(1) for the variables used.