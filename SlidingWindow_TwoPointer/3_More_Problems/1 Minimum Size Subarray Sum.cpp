class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int sum = 0;
        int minLen = 1e9;

        while(r < n){

            sum += nums[r];

            if(sum >= target){
                minLen = min(minLen, r - l + 1);

                while(sum >= target){

                    sum -= nums[l];
                    minLen = min(minLen, r - l + 1);
                    l++;

                }
            }

            r++;
        }

        if(minLen == 1e9) return 0;

        return minLen;
    }
};