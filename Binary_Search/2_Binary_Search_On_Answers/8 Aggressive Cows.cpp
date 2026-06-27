// Binary Search - Min Max Pattern

class Solution {
    bool canWePlace(vector<int> &stalls, int d, int k){
        int n = stalls.size();
        
        int lastCow = stalls[0];
        int cows = 1;
        
        for(int i = 0; i < n; i++){
            if(stalls[i] - lastCow >= d){
                lastCow = stalls[i];
                cows++;
            }
            if(cows >= k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();

        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
            
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(canWePlace(stalls, mid, k)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return high;
    }
};

//* Time Complexity: O(nlogn + nlogm) where n is the number of stalls and m is the range of the answer. The first term is for sorting the stalls, and the second term is for binary search over the possible distances.

//* Space Complexity: O(1) as we are using a constant amount of extra space. 

//! We have returned high because inititally low represents possible ans and high represents impossible ans. So, when the loop ends, due to opposite polarity of low and high, high will be the last possible answer.