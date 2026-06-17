class Solution {
    long long solve(int dice, int target, int k, vector<vector<long long>> &dp){
        if(target < 0) return 0;
        if(target > 0 && dice == 0) return 0;
        if(target == 0 && dice > 0) return 0;
        if(target == 0 && dice == 0) return 1;

        if(dp[dice][target] != -1) return dp[dice][target];

        long long ans = 0;
        long long mod = 1e9 + 7;

        for(int face = 1; face <= k; face++){
            ans = (ans + solve(dice - 1, target - face, k, dp)) % mod;
        }

        return dp[dice][target] = ans % mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long> (target + 1, -1));

        long long ans = solve(n, target, k, dp);
        long long mod = 1e9 + 7;

        return ans % mod;
    }
};
// Time Complexity: O(n * target * k)
// Space Complexity: O(n * target) + O(n)

//! Tabulation
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long> (target + 1, 0));

        long long mod = 1e9 + 7;

        dp[0][0] = 1;

        for(int dice = 1; dice <= n; dice++){
            for(int tar = 1; tar <= target; tar++){

                long long ans = 0;

                for(int face = 1; face <= k; face++){
                    if(tar - face < 0) continue;
                    ans = (ans + dp[dice - 1][tar - face]) % mod;
                }

                dp[dice][tar] = ans % mod;
            }
        }

        return dp[n][target] % mod;
    }
};
// Time Complexity: O(n * target * k)
// Space Complexity: O(n * target)

//! Space Optimized Tabulation
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        vector<long long> curr(target + 1, 0);
        vector<long long> prev(target + 1, 0);
        long long mod = 1e9 + 7;

        prev[0] = 1;

        for(int dice = 1; dice <= n; dice++){
            for(int tar = 1; tar <= target; tar++){

                long long ans = 0;

                for(int face = 1; face <= k; face++){
                    if(tar - face < 0) continue;
                    ans = (ans + prev[tar - face]) % mod;
                }

                curr[tar] = ans % mod;
            }
            prev = curr;
        }

        return prev[target] % mod;
    }
};
// Time Complexity: O(n * target * k)
// Space Complexity: O(2 * target) 
