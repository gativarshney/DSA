//! Using Dynamic Programing with Memoization (Top-Down Approach)
class Solution {
    bool solve(int idx, vector<int> &arr, vector<int> &dp){
        if(idx < 0 || idx >= arr.size()) return false;
        if(arr[idx] == 0) return true;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = 0;
        bool left = solve(idx - arr[idx], arr, dp);
        bool right = solve(idx + arr[idx], arr, dp);
        return dp[idx] = left || right; 
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(start, arr, dp);
    }
};
// Time Complexity: O(n) in the worst case, where n is the size of the input array. This is because in the worst case, we may have to explore all indices of the array.
// Space Complexity: O(n) due to the recursion stack and the dp array used for memoization.

//! Using Graph - BFS Approach
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            if(arr[idx] == 0) return true;
            
            int leftIdx = idx - arr[idx];
            int rightIdx = idx + arr[idx];

            if(leftIdx >= 0 && !vis[leftIdx]){
                q.push(leftIdx);
                vis[leftIdx] = 1;
            }
            if(rightIdx < n && !vis[rightIdx]){
                q.push(rightIdx);
                vis[rightIdx] = 1;
            }
        }
        return false;
    }
};
// Time Complexity: O(n) in the worst case, where n is the size of the input array. This is because in the worst case, we may have to explore all indices of the array.
// Space Complexity: O(n) due to the queue used for BFS and the visited array.