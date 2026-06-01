//! Swap without swapping data

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        head = head->next;
        ListNode* prev = NULL;

        while(temp != NULL && temp->next != NULL){
            ListNode* curr = temp;
            ListNode* nextNode = temp->next;
            ListNode* front = nextNode->next;

            nextNode->next = curr;
            curr->next = front;
            if(prev) prev->next = nextNode;

            prev = curr;
            temp = front;
        }

        return head;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as we are not using any extra space.