class Solution {
private:
    vector<int> NSE(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i); 
        }
        return ans;
    }
    vector<int> PSEE(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i] < nums[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i); 
        }
        return ans;
    }
    vector<int> NGE(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i); 
        }
        return ans;
    }
    vector<int> PGEE(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i); 
        }
        return ans;
    }
    long long smallestSum(vector<int> nums){
        long long totalSmallest = 0;
        vector<int> nse = NSE(nums);
        vector<int> psee = PSEE(nums);
        for(int i=0; i<nums.size(); i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            totalSmallest += (left * right * 1LL * nums[i]);
        }
        return totalSmallest;
    }
    long long largestSum(vector<int> nums){
        long long totalLargest = 0;
        vector<int> nge = NGE(nums);
        vector<int> pgee = PGEE(nums);
        for(int i=0; i<nums.size(); i++){
            int left = i - pgee[i];
            int right = nge[i] - i;
            totalLargest += (left * right * 1LL * nums[i]);
        }
        return totalLargest;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long largest = largestSum(nums);
        long long smallest = smallestSum(nums);
        return largest - smallest;
    }
};

//? TC: O(N) SC:O(N)