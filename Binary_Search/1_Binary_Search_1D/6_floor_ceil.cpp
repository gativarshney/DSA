// Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

// Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
// Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

// Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

private:
int getFloor(int x, vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= x){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int getCeil(int x, vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
public:
vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int floorIndex = getFloor(x, arr);
    int ceilIndex = getCeil(x, arr);
    int floorVal = -1, ceilVal = -1;
    if(floorIndex == -1){
        floorVal = -1;
    }else{
        floorVal = arr[floorIndex];
    }
    if(ceilIndex == -1){
        ceilVal = -1;
    }else{
        ceilVal = arr[ceilIndex];
    }
    return {floorVal, ceilVal};
}