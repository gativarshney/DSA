//*  Capacity To Ship Packages Within D Days

//! Optimal Solution

long long int sumWeight(vector<int>& weights){
    int n = weights.size();
    long long int sum = 0;
    for(int i=0; i<n; i++){
        sum += weights[i];
    }
    return sum;
}
int daysReq(vector<int>& weights, int mid){
    int n = weights.size();
    int load = 0, cntDay = 1;
    for(int i=0; i<n; i++){
        if(load + weights[i] > mid){
            cntDay++;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return cntDay;
}
int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    long long int low = *max_element(weights.begin(), weights.end());
    long long int high = sumWeight(weights);
    long long int ans = high;
    while(low <= high){
        long long int mid = low + (high - low)/2;
        if(daysReq(weights, mid) <= days){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

//? TC : O(log(sum-max+1) * n)