// Longest Substring Without Repeating Characters

#include<bits/stdc++.h>
using namespace std;

//! Brute Force
int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int n = s.length();
    for(int i=0; i<n; i++){
        int hash[256] = {0};
        for(int j=i; j<n; j++){
            if(hash[s[j]] == 0){
                hash[s[j]] = 1;
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
            else break;
        }
    }
    return maxLen;
}
// TC: O(N^2) SC: O(1)

//! Optimal Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        vector<int> hash(256, -1);
        int l = 0, r = 0, maxLen = 0;
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;            
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
// TC: O(N) SC: O(1)