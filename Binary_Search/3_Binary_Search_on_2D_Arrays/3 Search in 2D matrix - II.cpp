//! Brute Force
//* TC: O(m * n) SC: O(1)

//! Better (Binary Search)
//* TC: O( m log n) SC: O(1)

//! Optimised
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col - 1;

        while(rowIndex < row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];

            if(element == target){
                return 1;
            }
            
            if(element < target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }

        return 0;
    }
};
// TC: O(m + n)
// SC: O(1)