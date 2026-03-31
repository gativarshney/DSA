class Solution {
private:
    int f(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
        int n = arr.size();
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k=i; k<j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
            mini = min(steps, mini);
        }
        return dp[i][j] = mini;
    }
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(1, n-1, arr, dp);
    }
};
// Time Complexity: O(N^3) where N is the number of matrices. This is because we are using three nested loops to calculate the minimum number of multiplications.
// Space Complexity: O(N^2) for the dp array and O(N) for the recursive call stack, resulting in O(N^2) overall.