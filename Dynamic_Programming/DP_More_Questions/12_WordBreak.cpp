class Solution {
    bool solve(int idx, string &s, unordered_set<string> &st, int &maxWordLen, vector<int> &dp){
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        for(int i = idx; i < min(idx + maxWordLen, (int)s.size()); i++){
            temp += s[i];
            if(st.count(temp)){
               if(solve(i+1, s, st, maxWordLen, dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        int maxWordLen = 0;
        for(auto &it : wordDict){
            maxWordLen = max(maxWordLen, (int)it.size());
        }
        return solve(0, s, st, maxWordLen, dp);
    }
};
//* Time Complexity: O(n * m) where n is the length of the string s and m is the maximum length of the words in wordDict. In the worst case, we might check all possible substrings of s against the words in wordDict.
//* Space Complexity: O(n) due to the dp vector and the recursive stack space. Additionally, we use O(k) space for the unordered_set where k is the number of words in wordDict.