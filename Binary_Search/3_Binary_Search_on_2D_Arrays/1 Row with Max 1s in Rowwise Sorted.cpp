//! Brute Force
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxCount = 0;
        int row = 0;

        for(int i = 0; i < m; i++){
            int cnt = 0;

            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1) cnt++;
            }

            if(cnt > maxCount){
                maxCount = cnt;
                row = i;
            }
        }

        return {row, maxCount};
    }
};
// TC: O(m * n)
// SC: O(1)

//! Optimised Approach
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr.size();
        int n = arr[0].size();
        int maxOnes = 0;
        int row = -1;
        
        for(int i = 0; i < m; i++){
            int low = 0;
            int high = n-1;
            
            while(low <= high){
                int mid = low + (high - low) / 2;
                
                if(arr[i][mid] == 1){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            
            int ones = n - low;
            
            if(ones > maxOnes){
                maxOnes = ones;
                row = i;
            }
            
        }
        
        return row;
    }
};
// TC: O(m * log n)
// SC: O(1)