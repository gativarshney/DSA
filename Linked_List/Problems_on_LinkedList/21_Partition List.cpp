class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);

        ListNode* s = small;
        ListNode* l = large;

        ListNode* node = head;
        while(node){
            if(node->val < x){
                s->next = node;
                s = s->next;
            }
            else{
                l->next = node;
                l = l->next;
            }
            node = node->next;
        }
        s->next = large->next;
        l->next = NULL;
        head = small->next;
        return head;
    }
};
// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as we are using only constant extra space.