//? Constraints: 1 <= n <= 1000, that's why we can use the brute force method to check for prime numbers in the range, as it will not cause TLE for this constraint.

class Solution {
    int reverse(int n){
        int num = 0;
        while(n != 0){
            int d = n % 10;
            n = n / 10;
            num = num * 10 + d;
        }
        return num;
    }
    bool checkPrime(int n){
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int l = min(n, rev);
        int r = max(n, rev);
        int sum = 0;
        for(int i = l; i <= r; i++){
            if(checkPrime(i)){
                sum += i;
            }
        }
        return sum;
    }
};
// Time Complexity: O((r-l+1) * sqrt(n)) where r is the maximum of n and its reverse, and l is the minimum of n and its reverse.
// Space Complexity: O(1)


//! Optimized Using Sieve of Eratosthenes Method
class Solution {
    int reverse(int n){
        int num = 0;
        while(n != 0){
            int d = n % 10;
            n = n / 10;
            num = num * 10 + d;
        }
        return num;
    }
    vector<bool> sieve(int n){
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(prime[i]){
                for(int j = i * i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
        return prime;
    }
public:
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int l = min(n, rev);
        int r = max(n, rev);
        int sum = 0;
        vector<bool> prime = sieve(r);
        for(int i = l; i <= r; i++){
            if(prime[i]){
                sum += i;
            }
        }
        return sum;
    }
};
// Time Complexity: O(n log log n) for generating the sieve and O(r-l+1) for summing the primes in the range, where r is the maximum of n and its reverse, and l is the minimum of n and its reverse. 
//* So, overall time complexity is O(n log log n) + O(r-l+1).
//* Space Complexity: O(n) for the sieve array.