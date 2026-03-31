//! Recursion + Memoization
class Solution {
private:
    int f(int idx, int txn, int k, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx == n || txn == 2*k) return 0;
        if(dp[idx][txn] != -1) return dp[idx][txn];
        int profit = 0;
        if(txn % 2 == 0){
            profit = max(-prices[idx] + f(idx+1, txn+1, k, prices, dp), f(idx+1, txn, k, prices, dp));
        }
        else{
            profit = max(prices[idx] + f(idx+1, txn+1, k, prices, dp), f(idx+1, txn, k, prices, dp));
        }
        return dp[idx][txn] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k*2, -1));
        return f(0, 0, k, prices, dp);
    }
};
// Time Complexity: O(n*2k)
// Space Complexity: O(n*2k) + O(n) [Recursion Stack Space]

//! Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(k*2+1, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int txn=2*k-1; txn>=0; txn--){
                if(txn % 2 == 0){
                    dp[idx][txn] = max(-prices[idx] + dp[idx+1][txn+1], dp[idx+1][txn]);
                }
                else{
                    dp[idx][txn] = max(prices[idx] + dp[idx+1][txn+1], dp[idx+1][txn]);
                }
            }
        }
        return dp[0][0];
    }
};
// Time Complexity: O(n*2k)
// Space Complexity: O(n*2k)

//! Space Optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> front(k*2+1, 0), curr(k*2+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int txn=2*k-1; txn>=0; txn--){
                if(txn % 2 == 0){
                    curr[txn] = max(-prices[idx] + front[txn+1], front[txn]);
                }
                else{
                    curr[txn] = max(prices[idx] + front[txn+1], front[txn]);
                }
            }
            front = curr;
        }
        return front[0];
    }
};
// Time Complexity: O(n*2k)
// Space Complexity: O(2k)