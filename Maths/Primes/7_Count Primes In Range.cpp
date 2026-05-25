class Solution {
    vector<bool> sieve(int n){
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
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
    int countPrimes(int L, int R) {
        int cnt = 0;
        vector<bool>prime = sieve(R);
        for(int i = L; i <= R; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};
// Time Complexity: O(n log log n) for sieve + O(m) for counting primes in the range [L, R], where m is the number of integers in the range [L, R]
// Space Complexity: O(n) for sieve
//? For Q Queries, TC: O((R-L) * √R)
// So we can optimise it using prefix sum array to get the count of primes in O(1) time for each query after O(n) preprocessing time for sieve and prefix sum array.

//! Optimised Approach
class Solution {
    vector<bool> sieve(int n){
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
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
    int countPrimes(int L, int R) {
        int cnt = 0;
        vector<bool>prime = sieve(R);
        vector<int> preSum(R+1, 0);
        for(int i = 0; i <= R; i++){
            if(prime[i]){
                cnt++;
            }
            preSum[i] = cnt;
        }
        if(L <= 1) return preSum[R];
        int ans = preSum[R] - preSum[L-1];
        return ans;
    }
};
// Time Complexity: O(n log log n) for sieve + O(n) for prefix sum, where n is the maximum number in the range [L, R]
// Space Complexity: O(n) for sieve + O(n) for prefix sum, where n is the maximum number in the range [L, R]
//? For Q Queries, TC: O(R log log R) for sieve + O(R) for prefix sum + O(1) for each query

//! For Single Query, we can use approach-1 but for multiple queries, we can use approach-2 to get the count of primes in O(1) time for each query after O(n) preprocessing time for sieve and prefix sum array.