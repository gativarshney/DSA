class Solution {
public:
    bool rabinKarp(string &a, string &b) {

        int n = a.size();
        int m = b.size();

        int p = 7, mod = 101;
        int pl = 1, pr = 1;

        int hash_a = 0;
        int hash_b = 0;

        for(int i = 0; i < m; i++) {
            hash_b = (hash_b + 1LL * (b[i] - 'a' + 1) * pr) % mod;
            hash_a = (hash_a + 1LL * (a[i] - 'a' + 1) * pr) % mod;

            pr = (1LL * pr * p) % mod;
        }

        for(int i = 0; i <= n - m; i++) {

            if(hash_b == hash_a) {
                if(a.substr(i, m) == b) return true;
            }

            if(i == n - m) break;

            hash_a = (hash_a - 1LL * (a[i] - 'a' + 1) * pl % mod + mod) % mod;
            hash_a = (hash_a + 1LL * (a[i + m] - 'a' + 1) * pr) % mod;

            hash_b = (1LL * hash_b * p) % mod;

            pl = (1LL * pl * p) % mod;
            pr = (1LL * pr * p) % mod;
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {

        string temp = a;
        int cnt = 1;

        while(a.size() < b.size()) {
            a += temp;
            cnt++;
        }

        if(rabinKarp(a, b)){
            return cnt;
        }

        a += temp;
        cnt++;

        if(rabinKarp(a, b)){
            return cnt;
        }

        return -1;
    }
};

//! Time: Average O(n + m), Worst O((n + m) × m) because of hash collisions and substring verification.
//! Space: O(n + m) due to the repeated string.