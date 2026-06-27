class Solution {
    bool solve(vector<int> &nums, int k, int mid){
        int n = nums.size();
        int cnt = 1;
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }

        }

        if(cnt <= k) return true;
        return false;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(solve(nums, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};

//* Time Complexity: O(2*N + Nlog(sum - max_element)) 
//* Space Complexity: O(1)