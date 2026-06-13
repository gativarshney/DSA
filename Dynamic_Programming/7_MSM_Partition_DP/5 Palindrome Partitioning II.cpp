//! Recursive + Memoization
class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCost = 1e9; 

        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + f(j+1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return f(0, n, s, dp) - 1;
    }
};
// TC: O(N^3) for the nested loops and palindrome check
// SC: O(N) for the dp array + O(N) for the recursive call stack

//! Tabulation
class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            int minCost = 1e9; 

            for(int j = i; j < n; j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};
// TC: O(N^3) for the nested loops and palindrome check
// SC: O(N) for the dp array