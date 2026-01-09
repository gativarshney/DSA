//* Delete Nodes From Linked List Present in Array

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        while(head && st.find(head->val) != st.end()){
            head = head->next;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* temp = head;
        
        while(temp != nullptr){
            if(st.find(temp->val) != st.end()){
                ListNode* del = temp;
                prev->next = temp->next;
                delete(del);
                temp = prev->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        head = dummy->next;
        return head;
    }
};