// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// ? Brute force Solution
int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int zero = 0;
        for(int j=i; j<n; j++){
            if(nums[j] == 0) zero++;
            if(zero <= k){
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
            else break; 
        }
    }
    return maxLen;
}
//* TC: O(N^2) SC: O(1)

// ? Better Approach

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        int l = 0, r = 0, zeroes = 0;
        while(r < n){
            if(nums[r] == 0) zeroes++;
            while(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <= k){
                int len = r - l + 1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};
//* TC: O(2*N), SC:O(1)

//? Optimal Approach

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        int l = 0, r = 0, zeroes = 0;
        while(r < n){
            if(nums[r] == 0) zeroes++;
            if(zeroes > k){
                if(nums[l] == 0){
                    zeroes--;
                }
                l++;
            }
            if(zeroes <= k){
                int len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }
        return maxLen;
    } 
};
//* TC: O(N), SC: O(1)
