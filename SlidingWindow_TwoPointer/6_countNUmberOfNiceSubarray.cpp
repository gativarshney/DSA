// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it. Return the number of nice sub-arrays.

//? Using Hashmap, TC: O(N), SC: O(N) 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int sum = 0, cnt = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i] % 2);
            if(mpp.find(sum - k) != mpp.end()){
                cnt += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};

//? Optimised< TC: O(N), SC: O(1)
class Solution {
private:
    int atmost(vector<int>& nums, int k){
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < nums.size()){
            sum += (nums[r] % 2);
            while(sum > k){
                sum -= (nums[l] % 2);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};

// nums[] = {1,2,3,4,5,7} k = 3
// --> {1,0,1,0,1,1} then it becomes same as (5).cpp