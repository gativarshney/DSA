class Solution {
    
    bool solve(vector<int> &arr, int k, int pages){
        int n = arr.size();
        int students = 1;
        int currPages = 0;
            
        for(int i = 0; i < n; i++){
            if(currPages + arr[i] <= pages){
                currPages += arr[i];
            }
            else{
                students++;
                currPages = arr[i];
            }
        }
        if(students <= k) return true;
        return false;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(solve(arr, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;     //? Opposite polarity concept is used here. Initially, low represents impossible ans and high represents possible ans. So, when the loop ends, due to opposite polarity of low and high, low will be the last possible answer.
    }
    
};
//* Time Complexity: O(2*N + Nlog(sum - max_element)) 
//* Space Complexity: O(1) as we are using a constant amount of extra space.
