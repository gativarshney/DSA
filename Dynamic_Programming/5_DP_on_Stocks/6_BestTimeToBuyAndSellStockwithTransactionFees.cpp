//! Recursive + Memoization
class Solution {
private:
    int f(int idx, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            dp[idx][buy] = max(-prices[idx] + f(idx+1, 0, fee, prices, dp), f(idx+1, 1, fee, prices, dp));
        }
        else{
            dp[idx][buy] = max(prices[idx] + f(idx+1, 1, fee, prices, dp) - fee, f(idx+1, 0, fee, prices, dp));
        }
        return dp[idx][buy];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, fee, prices, dp);
    }
};
// Time Complexity: O(N*2) => O(N)
// Space Complexity: O(N*2) + O(N) => O(N)

//! Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    dp[idx][buy] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                }
                else{
                    dp[idx][buy] = max(prices[idx] + dp[idx+1][1] - fee, dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
// Time Complexity: O(N*2) => O(N)
// Space Complexity: O(N*2) => O(N)

//! Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int frontBuy = 0, frontNotBuy = 0, currBuy = 0, currNotBuy = 0; 
        for(int idx=n-1; idx>=0; idx--){
            currBuy = max(-1 * prices[idx] + frontNotBuy, frontBuy);
            currNotBuy = max(prices[idx] + frontBuy - fee, frontNotBuy);
            frontBuy = currBuy;
            frontNotBuy = currNotBuy;
        }
        return frontBuy;
    }
};
// Time Complexity: O(N*2) => O(N)
// Space Complexity: O(4) => O(1)