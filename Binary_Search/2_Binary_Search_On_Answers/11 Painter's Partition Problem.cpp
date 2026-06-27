class Solution {
    bool solve(vector<int> &arr, int k, int mid){
        int n = arr.size();
        int cnt = 1;
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            }
            else{
                cnt++;
                sum = arr[i];
            }

        }

        if(cnt <= k) return true;
        return false;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(solve(arr, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
        
    }
};