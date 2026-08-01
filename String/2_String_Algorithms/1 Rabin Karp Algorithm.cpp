//! Brute Force Algorithm for Pattern Searching

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        int n = pat.length();
        int m = txt.length();
        
        vector<int> ans;
        
        for(int i=0; i <= m-n; i++) {
            bool flag = true;
            
            for(int j=0; j < n; j++) {
                
                if(txt[i+j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(i);
        }
        
        return ans;
    } 
};

//* Time Complexity: O((m-n+1)*n) ~ O(m * n)
//* Space Complexity: O(1) 

//! Optimized solution using Rabin Karp Algorithm for Pattern Searching

class Solution{
    public:
    vector <int> search(string pat, string txt) {
        int n = txt.size();
        int m = pat.size();

        if(m > n) return {};

        vector<int> ans;

        int p = 7;
        int mod = 101;

        int pr = 1;
        int pl = 1;

        int hashpat = 0;
        int hashtxt = 0;

        for(int i = 0; i < m; i++){
            hashpat = (hashpat + (pat[i] - 'a' + 1) * pr) % mod;
            hashtxt = (hashtxt + (txt[i] - 'a' + 1) * pr) % mod;
            pr = (pr * p) % mod;
        }

        for(int i = 0; i <= n - m; i++){

            if(hashpat == hashtxt){
                if(txt.substr(i, m) == pat) ans.push_back(i);
            }

            if(i == n - m) break;

            hashtxt = ((hashtxt - (txt[i] - 'a' + 1) * pl) % mod + mod) % mod;
            hashtxt = (hashtxt + (txt[i + m] - 'a' + 1) * pr) % mod;

            hashpat = (hashpat * p) % mod;

            pl = (pl * p) % mod;
            pr = (pr * p) % mod;

        }

        return ans;
    }
};

//* Time Complexity: O(n)
//* Space Complexity: O(1)