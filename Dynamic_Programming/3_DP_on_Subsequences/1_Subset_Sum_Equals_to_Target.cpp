//! Recursive
class Solution {
private:
    bool f(int idx, int target, vector<int>&arr){
        if(target == 0) return true;    // if target is 0, then we can always make the target by not taking any element
        if(idx == 0) return (arr[idx] == target);
        
        bool notTake = f(idx-1, target, arr);
        bool take = false;
        if(target >= arr[idx]) take = f(idx-1, target - arr[idx], arr);
        return take | notTake;
    }
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return f(n-1, sum, arr);
    }
};
// Time Complexity: O(2^n)
// Space Complexity: O(n) (recursive stack space)

//! Memoization
class Solution {
private:
    bool f(int idx, int target, vector<int>&arr, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(dp[idx][target] != -1) return dp[idx][target];
        if(idx == 0) return (arr[idx] == target); 
        bool notTake = f(idx-1, target, arr, dp);
        bool take = false;
        if(target >= arr[idx]) take = f(idx-1, target - arr[idx], arr, dp);
        return dp[idx][target] = take | notTake;
    }
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(n-1, sum, arr, dp);
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum) + O(n) (dp array + recursive stack space)

//! Tabulation
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = 1;
        if(arr[0] <= sum) dp[0][arr[0]] = true; // if the first element is less than or equal to sum, then we can make the target by taking the first element   
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=sum; target++){
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(target >= arr[idx]) take = dp[idx-1][target - arr[idx]];
                dp[idx][target] = take | notTake;
            }
        }
        return dp[n-1][sum];
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)

//! Space Optimisation
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = curr[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[idx]) take = prev[target - arr[idx]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(sum)
