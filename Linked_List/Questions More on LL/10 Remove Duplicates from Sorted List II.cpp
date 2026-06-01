class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            if(curr && curr->next && curr->val == curr->next->val){
                while(curr && curr->next && curr->val == curr->next->val){
                    curr = curr->next;
                }
                curr = curr->next;
                prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};