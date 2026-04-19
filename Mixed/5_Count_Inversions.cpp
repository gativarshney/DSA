//* Using Merge Sort, TC: O(NlogN), SC: O(N)
class Solution {
    int merge(vector<int>&arr, int low, int mid, int high){
        int cnt = 0;
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int left, int right) {
        int cnt = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            cnt += mergeSort(arr, left, mid);
            cnt += mergeSort(arr, mid + 1, right);
            cnt += merge(arr, left, mid, right);
        }
        return cnt;
    }
public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int cnt = mergeSort(arr, 0, n-1);
        return cnt;
    }
};