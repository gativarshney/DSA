int binarySearch(vector<int> &a, int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(a[mid] == target) return mid;
    else if(a[mid] < target) return binarySearch(a, mid+1, high, target);
    return binarySearch(a, low, mid+1, target);
}