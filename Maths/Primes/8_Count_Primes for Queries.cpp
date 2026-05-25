//! Extremely efficient approach using Sieve of Eratosthenes and prefix sum
// For Q queries in range [L, R] to count primes

class Solution {
    vector<bool> sieve(int n){
        vector<bool> prime(n+1, true);
        if(n >= 0) prime[0] = false;
        if(n >= 1) prime[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(prime[i]){
                for(int j = i*i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

public:
    vector<int> primesInRange(vector<vector<int>>& queries){
        int maxR = 0;

        for(auto &q : queries){
            maxR = max(maxR, q[1]);
        }

        vector<bool> prime = sieve(maxR);

        // prefix sum
        vector<int> pre(maxR+1, 0);
        for(int i = 1; i <= maxR; i++){
            pre[i] = pre[i-1] + (prime[i] ? 1 : 0);
        }

        vector<int> ans;
        for(auto &q : queries){
            int L = q[0], R = q[1];

            if(L <= 1) ans.push_back(pre[R]);
            else ans.push_back(pre[R] - pre[L-1]);
        }

        return ans;
    }
};
// Time Complexity: O(n log log n) for sieve + O(n) for prefix sum + O(Q) for answering queries, where n is the maximum number in the range of queries and Q is the number of queries
// Space Complexity: O(n) for sieve + O(n) for prefix sum, where n is the maximum number in the range of queries