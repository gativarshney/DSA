//* Find Minimum in Rotated Sorted Array II (Duplicates Allowed)
//! LEETCODE HARD QUESTION

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            ans = min(ans, nums[mid]);
            low++, high--;
        }
        // Left half sorted
        else if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid+1;
        }
        // Right half sorted
        else if(nums[mid] <= nums[high]){
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }
    return ans;
}

//? do not use if(nums[low] <= nums[high]){ ans = min(ans, nums[low]); break;} in case of duplicates
//? store ans = min(ans, nums[mid]); in case of nums[low] == nums[mid] == nums[high], becoz of test case {2,2,2,2,2}
