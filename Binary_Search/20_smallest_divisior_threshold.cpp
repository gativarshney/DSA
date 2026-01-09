//* Find the Smallest Divisor Given a Threshold

//! Optimised Solution
bool possible(vector<int>& nums, int threshold, int divisor){
    int n = nums.size();
    long long int sum = 0;
    for(int i=0; i<n; i++){
        double val = (double)nums[i] / (double)divisor;
        int ceilVal = ceil(val);
        sum += ceilVal;
    }
    if(sum <= threshold) return true;
    return false;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    if(n > threshold) return -1;
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int divisor = high;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(possible(nums, threshold, mid)){
            divisor = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return divisor;
}
//? Time Complexity : O(N X log(maxElement))