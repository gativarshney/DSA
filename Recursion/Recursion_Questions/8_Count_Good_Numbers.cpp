class Solution {
private:
    long long power(long long x, long long n){
        long long mod = 1e9 + 7;
        if(n == 0) return 1;
        if(n == 1) return x;
        long long half = power(x, n/2);
        if(n % 2 == 0){
            return (half * half) % mod;
        }
        else{
            return (x * half * half) % mod;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long even = (n+1) / 2;
        long long odd = n / 2;
        long long ans = (power(5, even) * power(4, odd)) % mod;
        return ans % mod;
    }
};
// Time Complexity: O(log n) where n is the input number.
// Space Complexity: O(log n) for the recursion stack.