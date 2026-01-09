class Solution {
private:
    vector<int> NSE(vector<int>& heights){
        int n = heights.size();
        vector<int> arr(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) arr[i] = n;
            else arr[i] = st.top();
            st.push(i);
        }
        return arr;
    }
    vector<int> PSE(vector<int>& heights){
        int n = heights.size();
        vector<int> arr(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) arr[i] = -1; 
            else arr[i] = st.top();
            st.push(i);
        }
        return arr;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        int maxArea = 0;
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        for(int i=0; i<n; i++){
            int area = heights[i] * (nse[i] - pse[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

//* TC: O(5*N) as nse : O(2*N) --> Overall TC: O(N)
//* SC: O(N)


//! Most Optimal Code
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int topIdx = st.top();
                int topVal = heights[st.top()];
                st.pop();
                int nsIndex = i;
                int psIndex = (st.empty() ? -1 : st.top());
                int area = topVal * (nsIndex - psIndex - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int topIdx = st.top(); 
            int topVal = heights[st.top()];
            st.pop();
            int nsIndex = n;
            int psIndex = (st.empty() ? -1 : st.top());
            int area = topVal * (nsIndex - psIndex - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
//* TC: O(2*N)
//* SC: O(N)