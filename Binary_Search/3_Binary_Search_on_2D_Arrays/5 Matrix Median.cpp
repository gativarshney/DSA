//! Brute Force
int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> nums;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            nums.push_back(matrix[i][j]);
        }
    }

    sort(nums.begin(), nums.end());

    int k = (m * n) / 2;
    
    return nums[k];
}
// TC: O(m * n * log(m * n))
// SC: O(m * n)

//! Using Binary Search 

//...