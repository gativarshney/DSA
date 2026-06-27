// minimum number of days to make m bouquets

//! Brute Force Solution

bool possible(vector<int>& bloomDay, int day, int m, int k){
    int n = bloomDay.size();
    int cnt  = 0;
    int noOfBouquets = 0;
    for(int i=0; i<n; i++){
        if(bloomDay[i] <= day){
            cnt++;
        }
        else{
            noOfBouquets += cnt/k;
            cnt = 0;
        }
    }
    noOfBouquets += cnt/k;
    if(noOfBouquets >= m) return true;
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if(m * k > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    for(int i=mini; i<=maxi; i++){
        if(possible(bloomDay, i, m, k)){
            return i;
        }
    }
    return -1;
}
//? Time Complexity : O((maxi-mini+1) X N)

//! Optimal Solution

bool possible(vector<int>& bloomDay, int day, int m, int k){
    int n = bloomDay.size();
    int cnt  = 0;
    int noOfBouquets = 0;
    for(int i=0; i<n; i++){
        if(bloomDay[i] <= day){
            cnt++;
        }
        else{
            noOfBouquets += cnt/k;
            cnt = 0;
        }
    }
    noOfBouquets += cnt/k;
    if(noOfBouquets >= m) return true;
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if(1LL * m * k > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    int low = mini, high = maxi;
    int ans = maxi;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(possible(bloomDay, mid, m, k)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
//? Time Complexity : O(N * log(maxi-mini+1)) and Space Complexity : O(1)