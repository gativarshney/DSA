//! Recursive Approach
class Solution {
    bool solve(int idx, int cnt, string &s){
        if(cnt < 0) return false;
        if(idx == s.size()){
            if(cnt == 0) return true;
            return false;
        }
        if(s[idx] == '(') return solve(idx+1, cnt+1, s);
        if(s[idx] == ')') return solve(idx+1, cnt-1, s);
        return solve(idx+1, cnt, s) || solve(idx+1, cnt+1, s) || solve(idx+1, cnt-1, s);
    }
public:
    bool checkValidString(string s) {
        return solve(0, 0, s);
    }
};
// Time Complexity: O(3^n) since for each character we have three choices (treat it as '(', treat it as ')' or ignore it).
// Space Complexity: O(n) due to the recursive call stack in the worst case when all characters are '*'.

//! Memoization Approach
class Solution {
    bool solve(int idx, int cnt, string &s, vector<vector<int>> &dp){
        if(cnt < 0) return false;
        if(idx == s.size()){
            if(cnt == 0) return true;
            return false;
        }
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        if(s[idx] == '(') return dp[idx][cnt] = solve(idx+1, cnt+1, s, dp);
        if(s[idx] == ')') return dp[idx][cnt] = solve(idx+1, cnt-1, s, dp);
        return dp[idx][cnt] = solve(idx+1, cnt, s, dp) || solve(idx+1, cnt+1, s, dp) || solve(idx+1, cnt-1, s, dp);
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, s, dp);
    }
};
// Time Complexity: O(n^2) since we are using memoization to store results for each index and count combination, and there are at most n indices and n counts.
// Space Complexity: O(n^2) due to the dp array and the recursive call stack in the worst case when all characters are '*'.

//! Greedy Approach
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                mini = mini + 1;
                maxi = maxi + 1;
            }
            else if(s[i] == ')'){
                mini = mini - 1;
                maxi = maxi - 1;
            }
            else{
                mini = mini - 1;
                maxi = maxi + 1;
            }
            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }
        return (mini == 0);
    }
};
// Time Complexity: O(n) since we are iterating through the string once.
// Space Complexity: O(1) since we are using a constant amount of space to store