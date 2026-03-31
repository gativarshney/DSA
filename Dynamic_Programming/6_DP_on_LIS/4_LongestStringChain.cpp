class Solution {
private:
    bool compare(string &s1, string &s2){
        int m = s1.size(), n = s2.size();
        if(m != n + 1) return false;
        int i = 0, j = 0;
        while(i < m){
            if(s1[i] == s2[j]) i++, j++;
            else i++;
        }
        return (i == m && j == n);
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        vector<int> dp(n, 1);
        int maxi = 0;
        for(int idx=0; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(compare(words[idx], words[prev]) && dp[idx] < dp[prev] + 1){
                    dp[idx] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[idx]);
        }
        return maxi;
    }
};
// Time Complexity: O(n^2 * m) + O(nlogn) where n is the number of words and m is the average length of the words for the compare function and sorting the words.
// Space Complexity: O(n) for the dp array.