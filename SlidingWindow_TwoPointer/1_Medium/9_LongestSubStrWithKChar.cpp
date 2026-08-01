//? Brute Force; TC: O(N*N), SC:O(256)
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int maxLen = -1;
        for(int i=0; i<n; i++){
            unordered_map<char, int> mpp;
            for(int j=i; j<n; j++){
                mpp[s[j]]++;
                if(mpp.size() == k){
                    maxLen = max(maxLen, j-i+1);
                }
                else if(mpp.size() > k){
                    break;
                }
            }
        }
        return maxLen;
    }
};

//? Optimal

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        
        unordered_map<char, int> mpp;
        int maxLen = -1;
        
        while(r < n){
            mpp[s[r]]++;
            
            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            
            if(mpp.size() == k){
                int len = r - l + 1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        
        return maxLen;
    }
};
// TC: O(N), SC: O(256)