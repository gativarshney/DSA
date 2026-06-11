//? Brute Force Code
//* TC: O(N*N), SC: O(1)
class Solution {
private:
    int cal(vector<int>& height, int s, int e){
        int maxi = 0;
        for(int i=s; i<=e; i++){
            maxi = max(maxi, height[i]);
        }
        return maxi;
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        for(int i=0; i<n; i++){
            int leftMax = cal(height, 0, i-1);
            int rightMax = cal(height, i+1, n-1);
            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};

//? Better Approach
//* TC: O(3*N) SC: O(2*N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        prefixMax[0] = height[0];
        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }
        for(int i=0; i<n; i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};

//? Optimal Approach
//* TC: O(N), SC: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n-1;
        int totalWater = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] >= leftMax){
                    leftMax = height[l];
                }
                else{
                    totalWater += leftMax - height[l];
                }
                l++;
            }
            else{
                if(height[r] >= rightMax){
                    rightMax = height[r];
                }
                else{
                    totalWater += rightMax - height[r];
                }
                r--;
            }
        }

        return totalWater;
    }
};

//* Simplified Code of Optimal Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n-1;
        int ans = 0;
        while(l < r){
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if(leftMax < rightMax){
                ans += (leftMax - height[l]);
                l++;
            }
            else{
                ans += (rightMax - height[r]);
                r--;
            }
        }
        return ans;
    }
};

//! Using Stack --> 
int trap(vector<int>& height) {
    int n = height.size(), total = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top(); st.pop();
            if (st.empty()) break;
            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];
            total += distance * bounded_height;
        }
        st.push(i);
    }
    return total;
}
// TC: O(N), SC: O(N)