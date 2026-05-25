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
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = sieve(right);
        vector<int> temp;
        for(int i = left; i <= right; i++){
            if(prime[i]){
                temp.push_back(i);
            }
        }
        if(temp.size() == 1) return {-1, -1};
        int mini = INT_MAX;
        int start = -1, end = -1;
        for(int i = 1; i < temp.size(); i++){
            if((temp[i] - temp[i-1]) < mini){
                mini = temp[i] - temp[i-1];
                start = temp[i-1];
                end = temp[i];
            }
            else if((temp[i] - temp[i-1]) == mini && temp[i-1] < start){
                start = temp[i-1];
                end = temp[i];
            }
        }
        return {start, end};
    }
};
// Time Complexity: O(n log log n) for sieve + O(m) for finding closest primes, where m is the number of primes in the range [left, right]
// Space Complexity: O(n) for sieve + O(m) for temp vector, where m is the number of primes in the range [left, right]

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
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = sieve(right);
        int mini = INT_MAX;
        int start = -1, end = -1;
        int prev = -1;
        for(int i = left; i <= right; i++){
            if(prime[i]){
                if(prev != -1){
                    int diff = i - prev;
                    if(diff < mini){
                        mini = diff;
                        start = prev;
                        end = i;
                    }
                }
                prev = i;
            }
        }
        return {start, end};
    }
};
// Time Complexity: O(n log log n) for sieve + O(n) for finding closest primes, where n is the size of the range [left, right]
// Space Complexity: O(n) for sieve, where n is the size of the range [left, right]