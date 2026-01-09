class Solution {
private:
    int largestHistogram(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                int topIdx = st.top();
                int topVal = nums[st.top()];
                st.pop();
                int nsIdx = i;
                int psIdx = (st.empty() ? -1 : st.top());
                int area = topVal * (nsIdx - psIdx - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i); 
        }
        while(!st.empty()){
            int topIdx = st.top();
            int topVal = nums[st.top()];
            st.pop();
            int nsIdx = n;
            int psIdx = (st.empty() ? -1 : st.top());
            int area = topVal * (nsIdx - psIdx - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0) return 0;
        int maxArea = 0;
        vector<vector<int>> arr(m, vector<int>(n));
        for(int j=0; j<n; j++){
            int sum = 0;
            for(int i=0; i<m; i++){
                if(matrix[i][j] == '0'){
                    sum = 0;
                    arr[i][j] = 0;
                }
                else{
                    sum += 1;
                    arr[i][j] = sum;
                }
            }
        }
        for(int i=0; i<m; i++){
            int area = largestHistogram(arr[i]);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

// TC: O(m * n) + O(2 * n * m)
// SC: {O(m * n) --> arr }+ {O(N) --> stack }