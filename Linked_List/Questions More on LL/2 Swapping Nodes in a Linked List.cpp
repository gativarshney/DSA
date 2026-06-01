class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < k-1; i++){
            fast = fast->next;
        }

        ListNode* first = fast;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* second = slow;

        swap(first->val, second->val);

        return head;
    }
};
// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as we are not using any extra space.