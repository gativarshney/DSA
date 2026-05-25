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
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int maxNum = -1;
        for(int i = 0; i < n; i++){
            maxNum = max(maxNum, nums[i]);
        }
        vector<bool> prime = sieve(maxNum);
        int first = -1, last = -1;
        for(int i = 0; i < n; i++){
            if(prime[nums[i]]){
                if(first == -1) first = i;
                last = i;
            }
        }
        int maxDist = last - first;
        return maxDist;
    }
};
// Time Complexity: O(n + m log log m) where n is the size of the input array and m is the maximum number in the input array
// Space Complexity: O(m) for sieve, where m is the maximum number in the input array

//! For smaller Test cases like nums[i] ≤ 10^5 (or even 10^6)
class Solution {
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();

        int first = -1, last = -1;

        for(int i = 0; i < n; i++){
            if(isPrime(nums[i])){
                if(first == -1) first = i;
                last = i;
            }
        }

        if(first == -1) return 0;
        return last - first;
    }
};
// Time Complexity: O(n * √max(nums[i]))
// Space Complexity: O(1)