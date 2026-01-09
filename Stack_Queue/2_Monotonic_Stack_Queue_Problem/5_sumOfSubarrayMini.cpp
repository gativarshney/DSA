//? Brute Force
//* TC: O(N*N) SC: O(1)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = (int)1e9 + 7;
        for(int i=0; i<n; i++){
            int mini = arr[i];
            for(int j=i; j<n; j++){
                mini = min(mini, arr[j]); 
                sum = (sum + mini) % mod;
            }
        }
        return sum;
    }
};

//* Optimal Code
class Solution {
private:
    vector<int> nse(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> psee(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        long long mod = 1e9 + 7;
        vector<int> NSE = nse(arr);
        vector<int> PSEE = psee(arr);
        for(int i=0; i<n; i++){
            int left = i - PSEE[i];
            int right = NSE[i] - i;
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};
// NSE - next smaller element
// PSEE - previous smaller equal element
// {3, 1, 2, 4}, {1,2,4,7,3,5,6,1}, {1,1} --> test cases for code understanding

