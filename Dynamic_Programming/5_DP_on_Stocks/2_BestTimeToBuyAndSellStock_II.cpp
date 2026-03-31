//! Best Time to Buy and Sell Stock II
//* Recursion + Memoization
class Solution {
private:
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        long long profit = 0;
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            long long bought = -1 * prices[idx] + f(idx+1, 0, prices, dp);
            long long notBought = f(idx+1, 1, prices, dp);
            profit = max(bought, notBought);
        }
        else{
            long long sell = prices[idx] + f(idx+1, 1, prices, dp);
            long long notSell = f(idx+1, 0, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};
// Time Complexity: O(2*N) => O(N)
// Space Complexity: O(2*N) + O(N) => O(N)

//! Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                long long profit = 0;
                if(buy){
                    profit = max(-1 * prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                }
                else{
                    profit = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
// Time Complexity: O(2*N) => O(N)
// Space Complexity: O(2*N) => O(N)

//! Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(2, 0), curr(2, 0); 
        front[0] = front[1] = 0;
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                long long profit = 0;
                if(buy){
                    profit = max(-1 * prices[idx] + front[0], front[1]);
                }
                else{
                    profit = max(prices[idx] + front[1], front[0]);
                }
                curr[buy] = profit;
            }
            front = curr;
        }
        return front[1];
    }
};
// Time Complexity: O(2*N) => O(N)
// Space Complexity: O(2) => O(1)

//! More Optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int frontBuy = 0, frontNotBuy = 0, currBuy = 0, currNotBuy = 0; 
        for(int idx=n-1; idx>=0; idx--){
            currBuy = max(-1 * prices[idx] + frontNotBuy, frontBuy);
            currNotBuy = max(prices[idx] + frontBuy, frontNotBuy);
            frontBuy = currBuy;
            frontNotBuy = currNotBuy;
        }
        return frontBuy;
    }
};
// Time Complexity: O(N) => O(N)
// Space Complexity: O(1)