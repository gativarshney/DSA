class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m > n) return -1;
        if(m == 0) return -1;

        int p = 7, mod = 101;
        int pl = 1, pr = 1;
        int hash_n = 0;
        int hash_h = 0;

        for(int i = 0; i < m; i++){
            hash_n = hash_n + ((needle[i] - 'a' + 1) * pr) % mod;
            hash_h = hash_h + ((haystack[i] - 'a' + 1) * pr) % mod;

            pr = (pr * p) % mod;
        }

        for(int i = 0; i <= n - m; i++){

            if(hash_n == hash_h){
                if(haystack.substr(i, m) == needle) return i;
            }

            if(i == n - m) return -1;

            hash_h = (hash_h - ((haystack[i] - 'a' + 1) * pl) % mod + mod) % mod;
            hash_h = (hash_h + (haystack[i + m] - 'a' + 1) * pr) % mod;

            hash_n = (hash_n * p) % mod;

            pr = (pr * p) % mod; 
            pl = (pl * p) % mod; 
        }

        return -1;
    }
};