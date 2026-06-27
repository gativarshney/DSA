//* Kth Missing Positive Number

//! Brute Force
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}
//? TC : O(N)

//! Optimal
int findKthPositive(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        int missing = arr[high] - (high+1);
        if(missing < k) low = mid+1;
        else high = mid-1;
    }
    return low + k;
}

// [2,3,4,7,11] k = 5 --> ans = 9
// Iterate low and high --> low = index-4(11) and high = index-3(7)
// missing = arr[high] - (high + 1)
// ans = arr[high] + more
// more = k - missing

// Derivation:
// ans = arr[high] + more
// ans = arr[high] + k - missing
// ans = arr[high] + k - arr[high] + high + 1
// ans = k + high + 1
// or ans = low + k (low = high + 1)
//* Hence, ans = low + k || ans = high + 1 + k