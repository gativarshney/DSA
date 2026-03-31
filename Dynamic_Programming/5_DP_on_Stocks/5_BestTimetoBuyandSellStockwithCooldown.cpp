//! Recursion + Memoization
class Solution {
private:
    int f(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx >= n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + f(idx+1, 0, prices, dp), f(idx+1, 1, prices, dp));
        }
        else{
            profit = max(prices[idx] + f(idx+2, 1, prices, dp), f(idx+1, 0, prices, dp));
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
// Time Complexity: O(n*2)
// Space Complexity: O(n*2) + O(n) [Recursion Stack Space]

//! Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    dp[idx][buy] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                }
                else{
                    dp[idx][buy] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
// Time Complexity: O(n*2)
// Space Complexity: O(n*2)


//! Good Solution to remove *2 loop
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--){
            dp[idx][1] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
            dp[idx][0] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
        }
        return dp[0][1];
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)

//! Space Optimization - 3 vector required - front1, front2 and curr
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front1(2, 0), front2(2, 0), curr(2, 0);
        for(int idx=n-1; idx>=0; idx--){
            curr[1] = max(-prices[idx] + front1[0], front1[1]);
            curr[0] = max(prices[idx] + front2[1], front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return front1[1];
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)