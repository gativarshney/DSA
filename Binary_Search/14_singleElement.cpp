//* Single Element in a Sorted Array

//? Time Complexity : O(N)
int singleNonDuplicate_BruteForce_I(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    for(int i=0; i<n; i++){
        if(i == 0){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        else if(i == n-1){
            if(nums[i] != nums[i-1]){
                return nums[i];
            }
        }
        else{
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        }
    }
    return -1;
}   
int single_BruteForce_II(vector<int>& arr) {
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
//? Time Complexity : O(logN)
int single_Optimal(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        //? Left Half
        if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])){
            low = mid+1;
        }
        //? Right Half
        if((mid%2 == 0 && nums[mid] == nums[mid-1]) || (mid%2 == 1 && nums[mid] == nums[mid+1])){
            high = mid-1;
        }
    }
    return -1;
}