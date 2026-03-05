//? Return the number of combinations that make up that amount. 
//? If that amount of money cannot be made up by any combination of the coins, return 0.

//! Recursion
// Time Complexity: greater than O(2^(N*amount)) because in the worst case, we can have two choices (take or not take) for each coin and for each amount, leading to an exponential number of combinations.
// Space Complexity: can be greater than O(N) or equals to O(amount) for the recursion stack in the worst case.

//! Recursion + Memoization
class Solution {
private:
    int solve(int idx, int target, vector<int>&coins, vector<vector<int>>&dp){
        if(idx == 0){
            if(target % coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int notTake = solve(idx-1, target, coins, dp);
        int take = 0;
        if(coins[idx] <= target) take = solve(idx, target-coins[idx], coins, dp);
        return dp[idx][target] = notTake + take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};
// Time Complexity: O(N*amount) where N is the number of coins and amount is the target amount.
// Space Complexity: O(N*amount) for the dp array and O(N) for the recursion stack.

//! Tabulation & Space Optimization
//* Giving Runtime Error - Need to check the code again. - I guess useing long long int instead of int for dp array will solve the problem because the number of combinations can be very large.
