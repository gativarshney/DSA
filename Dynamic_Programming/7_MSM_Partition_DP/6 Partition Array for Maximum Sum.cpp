//! Recursion + Memoization
class Solution {
    int f(int idx, int k, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if(idx == n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int len = 0;
        int maxSum = INT_MIN;
        int maxi = INT_MIN;

        for(int j = idx; j < min(idx + k, n); j++){
            len++;
            maxi = max(maxi, arr[j]);

            int sum = maxi * len + f(j+1, k, arr, dp);
            maxSum = max(maxSum, sum);
        }

        return dp[idx] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return f(0, k, arr, dp);
    }
};
// TC: O(N*K) for the nested loops
// SC: O(N) for the dp array + O(N) for the recursive call stack

//! Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int idx = n-1; idx >= 0; idx--){
            int len = 0;
            int maxSum = INT_MIN;
            int maxi = INT_MIN;

            for(int j = idx; j < min(idx + k, n); j++){
                len++;
                maxi = max(maxi, arr[j]);

                int sum = maxi * len + dp[j+1];
                maxSum = max(maxSum, sum);
            }

            dp[idx] = maxSum;
        }

        return dp[0];
    }
};
// TC: O(N*K) for the nested loops
// SC: O(N) for the dp array