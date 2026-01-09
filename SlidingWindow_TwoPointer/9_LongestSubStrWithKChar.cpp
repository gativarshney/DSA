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