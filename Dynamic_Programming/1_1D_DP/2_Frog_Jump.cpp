//! Memoization Code
class Solution {
private:
    int dpCost(int n, vector<int> &dp, vector<int> &height){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int left = INT_MAX, right = INT_MAX;
        left = dpCost(n-1, dp, height) + abs(height[n] - height[n-1]);
        if(n > 1) right = dpCost(n-2, dp, height) + abs(height[n] - height[n-2]);
        return dp[n] = min(left, right);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, -1);
        return dpCost(n-1, dp, height);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) for recursion stack + O(n) for dp array = O(n) in case of memorization

//! Tabulation Code
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for(int i=1; i<n; i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1){
                ss = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(fs, ss);
        }
        return dp[n-1];
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array = O(n) in case of tabulation


//! Space Optimization
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev2 = 0, prev = 0;
        for(int i=1; i<n; i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1){
                ss = prev2 + abs(height[i] - height[i-2]);
            }
            int curi = min(fs, ss);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};