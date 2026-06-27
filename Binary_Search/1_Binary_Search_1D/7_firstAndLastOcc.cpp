vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0) return {-1,-1};
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    if(lb == nums.size() || nums[lb] != target ){
        return {-1,-1};
    }
    return {lb, ub-1};
}

//* 2nd Method

private:
int firstOcc(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            first = mid;
            high = mid-1;
        }
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return first;
}
int lastOcc(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            last = mid;
            low = mid+1;
        }
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return last;
}
public:
vector<int> searchRange(vector<int>& nums, int target) {
    int first = firstOcc(nums, target);
    if(first == -1) return {-1,-1};
    int last = lastOcc(nums, target);
    return {first, last};
}
