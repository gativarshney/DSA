private:
int firstOcc(vector<int>& arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] > x) high = mid-1;
        else low = mid+1;
    }
    return first;
}
int lastOcc(vector<int>& arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] > x) high = mid-1;
        else low = mid+1;
    }
    return last;
}
public:
int countFreq(vector<int>& arr, int target) {
    int first = firstOcc(arr, target);
    if(first == -1) return 0;
    int last = lastOcc(arr, target);
    return last - first + 1;
}