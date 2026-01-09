//? Brute Force; O(N*N), SC: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            vector<int> hash(26, 0); 
            int maxFreq = 0;
            for(int j=i; j<n; j++){
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                int changes = (j-i+1) - maxFreq;
                if(changes <= k){
                    maxLen = max(maxLen, j-i+1);
                }
                else break;
            }
        }
        return maxLen;
    }
};

// better : O(2 * N * 26), SC: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0, maxFreq = 0;
        vector<int> hash(26, 0);
        while(r < n){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            while((r-l+1) - maxFreq > k){
                hash[s[l] - 'A']--;
                l++;
                maxFreq = 0;
                for(int i=0; i<26; i++){
                    maxFreq = max(maxFreq, hash[i]);
                }
            }
            if(((r-l+1) - maxFreq) <= k){
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }
        return maxLen;
    }
};

//? Optimised Solution , TC: O(N), SC: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0, maxFreq = 0;
        vector<int> hash(26, 0);
        while(r < n){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            if((r-l+1) - maxFreq > k){
                hash[s[l] - 'A']--;
                l++;
            }
            if(((r-l+1) - maxFreq) <= k){
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }
        return maxLen;
    }
};

// why to decrease maxFreq? kyuki ab maxLen hi increase krni hai, if maxLen is already 5 then there is no point to be put it for 4, so for it we just need to increase r ie. r++