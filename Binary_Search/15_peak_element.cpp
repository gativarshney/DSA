//* "Find Peak Element", If the array contains multiple peaks, return the index to any of the peaks.
// nums[-1] = nums[n] = -∞

// Time Complexity : O(N)
int findPeakElement_BruteForce(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n; i++){
        if((i == 0 || nums[i] > nums[i-1]) && (i == n-1 || nums[i] > nums[i+1])) return i;
    }
    return -1;
}
// Time Complexity : O(logN)
int findPeakElement_Optimal(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid] > nums[mid-1]) low = mid+1;   // mid on increasing curve
        else if(nums[mid] > nums[mid+1]) high = mid-1;  // mid on decresing curve
        else low = mid+1;       //! important for test cases like {1,5,1,2,1} --> {5,1,2} --> mid = 1 none of the above test case will work so it's important 
        //* in else statement we can also write "else high = mid-1"

    }
    return -1;
}

//? Or simpley just write this
if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
else if(nums[mid] > nums[mid-1]) low = mid+1;  
else high = mid-1; // just else will cover all