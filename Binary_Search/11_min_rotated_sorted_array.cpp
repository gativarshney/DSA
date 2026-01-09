//* Find Minimum in Rotated Sorted Array

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;

        // Search space is already sorted
        if(nums[low] <= nums[high]){
            ans = min(ans, nums[low]);
            break;
        }

        // Left Half Sorted
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid+1;
        }

        // Right Half Sorted
        else if(nums[mid] <= nums[high]){
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }
    return ans;
}
// TC for Unique : O(logN)
// TC for Duplicates: O(logN) in avg and worst case and O(n/2) in worst case
