class Solution {
    long long cnt = 0;

    void merge(vector<int>&arr, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
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
        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
    }

    void countPairs(vector<int> &arr, int low, int mid, int high){
        int right = mid + 1;
        for(int i = low; i <= mid; i++){
            while(right <= high && (long long)arr[i] > 2LL * arr[right])
                right++;
            cnt += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            countPairs(arr, left, mid, right);
            merge(arr, left, mid, right);
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        cnt = 0;
        mergeSort(nums, 0, n - 1);
        return (int)cnt;
    }
};
// Time Complexity: O(N log N) due to merge sort and counting pairs
// Space Complexity: O(N) due to temporary array used in merge function

//! Remove cnt as global variable and return it from mergeSort function, then add it to the countPairs function. This way we can avoid using a global variable and make the code cleaner.
class Solution {
    long long countPairs(vector<int>& arr, int low, int mid, int high) {
        long long cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    long long mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long cnt = 0;
        cnt += mergeSort(arr, left, mid);
        cnt += mergeSort(arr, mid + 1, right);
        cnt += countPairs(arr, left, mid, right);
        merge(arr, left, mid, right);
        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = mergeSort(nums, 0, n - 1);
        return (int)cnt;
    }
};
// Time Complexity: O(N log N) due to merge sort and counting pairs
// Space Complexity: O(N) due to temporary array used in merge function