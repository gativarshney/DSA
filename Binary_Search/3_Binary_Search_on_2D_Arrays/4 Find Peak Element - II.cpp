class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int maxColIndex = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();

            int up = (mid > 0) ? mat[mid - 1][maxColIndex] : -1;
            int down = (mid + 1 < m) ? mat[mid + 1][maxColIndex] : -1;

            int maxColValue = mat[mid][maxColIndex];

            if(maxColValue > up && maxColValue > down){
                return {mid, maxColIndex};
            }
            else if(maxColValue < up){
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return {-1, -1};
    }
};
// TC: O(n * log m)
// n for finding max element
// log m for binary search in rows
// SC: O(1)