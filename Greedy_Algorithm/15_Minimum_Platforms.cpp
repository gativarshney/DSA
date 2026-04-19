class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms = 0;
        int minPlatforms = INT_MIN;
        int i = 0, j = 0;
        while(i < arr.size()){
            if(arr[i] <= dep[j]){
                platforms++;
                minPlatforms = max(minPlatforms, platforms);
                i++;
            }
            else {
                platforms--;
                j++;
            }
        }
        return minPlatforms;
    }
};

// Time Complexity: O(n log n) due to the sorting step, where n is the number of trains.    
// Space Complexity: O(1) since we are using a constant amount of space to store the platform count and indices.
//* We sort the arrival and departure times separately. Then we use two pointers to traverse both lists