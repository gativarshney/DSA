class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || (head->next == NULL && n == 1)) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        for(int i = 0; i < n-1; i++){
            fast = fast->next;
        }

        if(fast->next == NULL) return head->next;

        while(fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = slow->next;

        return head;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as we are not using any extra space.