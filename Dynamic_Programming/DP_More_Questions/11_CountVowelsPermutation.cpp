class Solution {
    int mod = 1e9 + 7;
    int solve(int idx, int &n, int last, vector<vector<long long>> &dp){
        if(idx == n-1) return 1;
        if(dp[idx][last] != -1) return dp[idx][last];
        if(last == 0){
            return dp[idx][last] = 1LL * solve(idx + 1, n, 1, dp) % mod;
        }
        if(last == 1){
            long long x = 1LL * solve(idx + 1, n, 0, dp);
            long long y = 1LL * solve(idx + 1, n, 2, dp);
            return dp[idx][last] = (x + y) % mod;
        }
        if(last == 2){
            long long x = 1LL * solve(idx + 1, n, 0, dp);
            long long y = 1LL * solve(idx + 1, n, 1, dp);
            long long z = 1LL * solve(idx + 1, n, 3, dp);
            long long w = 1LL * solve(idx + 1, n, 4, dp);
            return dp[idx][last] = (x + y + z + w) % mod;
        }
        if(last == 3){
            long long x = 1LL * solve(idx + 1, n, 2, dp);
            long long y = 1LL * solve(idx + 1, n, 4, dp);
            return dp[idx][last] = (x + y) % mod;
        }
        else{
            long long x = 1LL * solve(idx + 1, n, 0, dp);
            return dp[idx][last] = x % mod;
        }
    }
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        // a-> 0, e->1, i->2, o->3, u->5
        vector<vector<long long>> dp(n, vector<long long>(5, -1));
        long long ans = solve(0, n, 0, dp) % mod;
        ans += solve(0, n, 1, dp) % mod;
        ans += solve(0, n, 2, dp) % mod;
        ans += solve(0, n, 3, dp) % mod;
        ans += solve(0, n, 4, dp) % mod;
        int result = (int)(ans % mod);
        return result;
    }
};
// Time Complexity: O(n * 5) == O(n) due to memoization
// Space Complexity: O(n * 5) == O(n) due to recursive stack space