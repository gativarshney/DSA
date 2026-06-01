class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        stack<int> st;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        vector<int> ans(n, 0);
        st.push(arr[n-1]);
        
        for(int i = n-2; i >= 0; i--){
            int curr = arr[i];
            
            if(st.top() > curr){
                ans[i] = st.top();
            }
            else{
                while(!st.empty() && st.top() <= curr){
                    st.pop();
                }
                if(st.empty()) ans[i] = 0;
                else ans[i] = st.top();
            }
            st.push(curr);
        }

        return ans;
    }
};