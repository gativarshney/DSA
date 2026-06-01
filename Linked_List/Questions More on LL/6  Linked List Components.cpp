class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        if(head == NULL) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* temp = head;
        bool flag = false;
        int cnt = 0;

        while(temp != NULL){
            if(st.count(temp->val)){
                flag = true;
            }
            else{
                if(flag == true){
                    cnt++;
                    flag = false;
                }
            }

            temp = temp->next;
        }

        if(flag == true) cnt++;

        return cnt;
    }
};