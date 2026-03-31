//! Best Time to Buy and Sell Stock III
//* Recursion + Memoization
class Solution {
private:
    int f(int idx, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(cap == 0) return 0;
        if(idx == n) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        long long profit = 0;
        if(buy){
            profit = max(-prices[idx] + f(idx+1, 0, cap, prices, dp), f(idx+1, 1, cap, prices, dp));
        }
        else{
            profit = max(prices[idx] + f(idx+1, 1, cap-1, prices, dp), f(idx+1, 0, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};
// Time Complexity: O(2*3*N) => O(N)
// Space Complexity: O(2*3*N) + O(N) due to recursion stack => O(N)

//! Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + dp[idx+1][1][cap-1], dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
// Time Complexity: O(2*3*N) => O(N)
// Space Complexity: O(2*3*N) => O(N)

//! Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> front(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + front[0][cap], front[1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + front[1][cap-1], front[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            front = curr;
        }
        return front[1][2];
    }
};
// Time Complexity: O(2*3*N) => O(N)
// Space Complexity: O(2*3) => O(1)


//! Approach 2: Using N*4 instead of 3D dp array
//* Recursion + Memoization
class Solution {
private:
    int f(int idx, int transaction, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx == n || transaction == 4) return 0;
        if(dp[idx][transaction] != -1) return dp[idx][transaction];
        int profit = 0;
        if(transaction % 2 == 0){
            profit = max(-prices[idx] + f(idx+1, transaction+1, prices, dp), f(idx+1, transaction, prices, dp));
        }
        else{
            profit = max(prices[idx] + f(idx+1, transaction+1, prices, dp), f(idx+1, transaction, prices, dp));
        }
        return dp[idx][transaction] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, 0, prices, dp);
    }
};
// Time Complexity: O(4*N) => O(N)
// Space Complexity: O(4*N) + O(N) => O(N)

//! Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int transaction=3; transaction>=0; transaction--){
                if(transaction % 2 == 0){
                    dp[idx][transaction] = max(-prices[idx] + dp[idx+1][transaction+1], dp[idx+1][transaction]);
                }
                else{
                    dp[idx][transaction] = max(prices[idx] + dp[idx+1][transaction+1], dp[idx+1][transaction]);
                }
            }
        }
        return dp[0][0];
    }
};
// Time Complexity: O(4*N) => O(N)
// Space Complexity: O(4*N) => O(N)

//! Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(5, 0), curr(5, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int transaction=3; transaction>=0; transaction--){
                if(transaction % 2 == 0){
                    curr[transaction] = max(-prices[idx] + front[transaction+1], front[transaction]);
                }
                else{
                    curr[transaction] = max(prices[idx] + front[transaction+1], front[transaction]);
                }
            }
            front = curr;
        }
        return front[0];
    }
};
// Time Complexity: O(4*N) => O(N)
// Space Complexity: O(4) => O(1)