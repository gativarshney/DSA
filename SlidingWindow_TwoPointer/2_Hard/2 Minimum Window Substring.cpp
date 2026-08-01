//! Brute Force Approach
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m > n) return "";

        int minLen = 1e9;
        int startingIdx = 0;

        for(int i = 0; i < n; i++){

            vector<int> hash(256, 0);
            int cnt = 0;

            for(int j = 0; j < m; j++) hash[t[j]]++;

            for(int j = i; j < n; j++){
                if(hash[s[j]] > 0) cnt++;

                hash[s[j]]--;

                if(cnt == m){
                    if(minLen > j - i + 1){
                        minLen = j - i + 1;
                        startingIdx = i;
                    }
                    break;
                }
            }
        }

        if(minLen == 1e9) return "";

        string ans = s.substr(startingIdx, minLen);

        return ans;
    }
};
//* TC: O(n^2) where n is the length of string s
//* SC: O(256) = O(1) for hash array


//! Optimized Approach: Sliding Window + Two Pointer
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m > n) return "";

        int minLen = 1e9;
        int startingIdx = -1;
        int cnt = 0;

        vector<int> hash(256, 0);
        for(int j = 0; j < m; j++){
            hash[t[j]]++;
        }

        int l = 0, r = 0;

        while(r < n){

            if(hash[s[r]] > 0){     
                cnt++;
            }
            hash[s[r]]--;

            while(cnt == m){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    startingIdx = l;
                }

                hash[s[l]]++;

                if(hash[s[l]] > 0) cnt--;

                l++;
            }
            
            r++;
        }

        if(startingIdx == -1) return "";

        string ans = s.substr(startingIdx, minLen);

        return ans;
    }
};
// * TC: O(2*n + m) where n is the length of string s
// * SC: O(256) = O(1) for hash array