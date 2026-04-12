class Solution {
    int solve(int idx, string &s, unordered_set<string> &st, int &maxWordLen, vector<int> &dp){
        int n = s.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        string temp = "";
        for(int i=idx; i < min((int)s.size(), idx + maxWordLen); i++){
            temp += s[i];
            if(st.count(temp)){
                ans = min(ans, solve(i+1, s, st, maxWordLen, dp));
            }
        }
        ans = min(ans, 1 + solve(idx+1, s, st, maxWordLen, dp));
        return dp[idx] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        int maxWordLen = 0;
        for(auto it : st){
            maxWordLen = max((int)it.size(), maxWordLen);
        }
        vector<int> dp(n, -1);
        return solve(0, s, st, maxWordLen, dp);
    }
};

//* Time Complexity: O(n * m) where n is the length of the string s and m is the maximum length of the words in dictionary. In the worst case, it can be O(n^2) if all characters in s are different and not present in the dictionary, leading to checking all possible substrings of s against the words in the dictionary.
//* Space Complexity: O(n) due to the dp vector and the recursive stack space. Additionally, we use O(k) space for the unordered_set where k is the number of words in dictionary.