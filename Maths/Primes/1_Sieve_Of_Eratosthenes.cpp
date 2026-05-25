//! Count Primes - Given an integer n, return the number of prime numbers that are strictly less than n.


//Brute Force Method: TLE
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// Time Complexity: O(n * sqrt(n))
// Space Complexity: O(1)

//* Better Sieve of Eratosthenes Method is the Solution of this problem, others will cause TLE
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n+1, true);

        prime[0] = prime[1] = false;
        
        for(int i = 2; i < n; i++){
            if(prime[i]){
                count++;
                for(int j = 2*i; j<n; j = j+i){
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};

//? Key Observation: we can just start from j = i * i because all the smaller multiples of i will have already been marked as non-prime by smaller primes. This optimization significantly reduces the number of iterations and improves the efficiency of the algorithm.

//! Optmized Sieve of Eratosthenes Method
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        int cnt = 0;
        
        for(int i = 2; i * i < n; i++){
            if(prime[i] == true){
                for(int j = i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(prime[i] == true) cnt++;
        }
        return cnt;
    }
};
//! Time complexity: O(n log log n) and space complexity: O(n).
// It works in 2 phases:
// 1. Marking non-prime numbers: We iterate through the numbers starting from 2 up to the square root of n. For each prime number found, we mark all of its multiples as non-prime. This step takes O(n log log n) time.
// 2. Counting prime numbers: After marking non-prime numbers, we iterate through the boolean array to count how many numbers are still marked as prime. This step takes O(n) time.
