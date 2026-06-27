//* Find out how many times has an array been rotated

// arr[5] = {3, 4, 5, 1, 2} --> result = 3 which is the index of min value, so use "minimum in rotated sorted array" method to find index

int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            break;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            low = mid+1;
        }
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
            high = mid-1;
        }
    }
    return index;
}