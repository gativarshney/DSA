//! Approach - 1
void printPrimeFactorization(int n) {
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                cout << i << " ";
                n = n / i;
            }
        }
    }
    if(n > 1) cout << n << " ";
}
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

//! Approach - 2 (Using Sieve of Eratosthenes)
class Solution {
  public:
    vector<int> findPrimeFactors(int N) {
        vector<int> res;
        vector<int> spf(N+1);
        for(int i = 0; i < N+1; i++) spf[i] = i;
        for(int i = 2; i*i <= N; i++){
            if(spf[i] == i){
                for(int j = i*i; j <= N; j += i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }
        while(N != 1){
            res.push_back(spf[N]);
            N = N / spf[N];
        }
        return res;
    }
};
// Time Complexity: O(n) for spf initialisation + O(n log log n) for sieve + O(log n) for finding prime factors, where n is the input number
// Space Complexity: O(n) for sieve + O(log n) for result vector, where n is the input number
//? Overall TC: O(n log log n) and SC: O(n)
