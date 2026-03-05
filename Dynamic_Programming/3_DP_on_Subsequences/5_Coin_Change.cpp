//! Recursion
// Time Complexity: greater than O(2^(N*amount)) because in the worst case, we can have two choices (take or not take) for each coin and for each amount, leading to an exponential number of combinations.
// Space Complexity: can be greater than O(N) for the recursion stack.

//! Recursion + Memoization
class Solution {
private:
    int solve(int idx, int target, vector<int>&coins, vector<vector<int>>&dp){
        if(idx == 0){
            if(target % coins[idx] == 0){
                return target / coins[idx];
            }
            else return 1e9;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int notTake = 0 + solve(idx-1, target, coins, dp);
        int take = 1e9;
        if(coins[idx] <= target) take = 1 + solve(idx, target-coins[idx], coins, dp);
        return dp[idx][target] = min(notTake, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
// Time Complexity: O(N*amount) where N is the number of coins and amount is the target amount.
// Space Complexity: O(N*amount) for the dp array and O(N) for the recursion stack.

//! Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }
        for(int idx=1; idx<n; idx++){
            for(int target=0; target<=amount; target++){
                int notTake = 0 + dp[idx-1][target];
                int take = 1e9;
                if(coins[idx] <= target) take = 1 + dp[idx][target-coins[idx]];
                dp[idx][target] = min(notTake, take);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};
// Time Complexity: O(N*amount) where N is the number of coins and amount is the target amount.
// Space Complexity: O(N*amount) for the dp array.

//! Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int i=1; i<=amount; i++){
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        }
        for(int idx=1; idx<n; idx++){
            for(int target=0; target<=amount; target++){
                int notTake = 0 + prev[target];
                int take = 1e9;
                if(coins[idx] <= target) take = 1 + curr[target-coins[idx]];
                curr[target] = min(notTake, take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};
// Time Complexity: O(N*amount) where N is the number of coins and amount is the target amount.
// Space Complexity: O(amount) for the prev and curr arrays.