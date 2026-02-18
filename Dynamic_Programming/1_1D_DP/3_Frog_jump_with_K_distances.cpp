//! Pure Recursion Code
int solve(int i, vector<int>& h, int k) {
    if(i == 0) return 0;
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++) {
        if(i - j >= 0) {
            int jump = solve(i - j, h, k) + abs(h[i] - h[i - j]);
            ans = min(ans, jump);
        }
    }
    return ans;
}
int frogJumpK(int n, vector<int>& height, int k) {
    return solve(n - 1, height, k);
}
// Time Complexity: O(k^n)
// Space Complexity: O(n) for recursion stack

//! Memoization Code (Top Down)
int solve(int i, vector<int>& h, int k, vector<int>& dp) {
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++) {
        if(i - j >= 0) {
            int jump = solve(i - j, h, k, dp) + abs(h[i] - h[i - j]);
            ans = min(ans, jump);
        }
    }
    return dp[i] = ans;
}
int frogJumpK(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1);
    return solve(n - 1, height, k, dp);
}
// Time Complexity: O(n*k) because we are solving for n states and for each state we are doing k work
// Space Complexity: O(n) for recursion stack + O(n) for dp array = O(n) in case of memorization

//! Tabulation Code (Bottom Up)
int frogJumpK(int n, vector<int>& h, int k) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        int ans = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int jump = dp[i - j] + abs(h[i] - h[i - j]);
                ans = min(ans, jump);
            }
        }
        dp[i] = ans;
    }
    return dp[n - 1];
}
// Time Complexity: O(n*k) because we are solving for n states and for each state we are doing k work
// Space Complexity: O(n) for dp array = O(n) in case of tabulation


//! NOTE:
// Cannot apply space optimization in this problem because we need to access dp[i-j] for j = 1 to k, which means we need to access all the previous k states, so we cannot reduce the space complexity to O(1) in this case.
// Although we can reduce the space complexity to O(k) by using a sliding window of size k to store the last k states, but it will rarely used. 