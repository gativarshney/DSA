class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head;
        int n = 0;
        while(tail){
            n++;
            tail = tail->next;
        }
        k = k % n;
        if(k == 0) return head;
        for(int i=0; i<k; i++){
            ListNode* temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            ListNode* last = temp->next;
            temp->next = nullptr;
            last->next = head;
            head = last;
        }
        return head;
    }
};
// Time Complexity: O(n * (k % n)) where n is the number of nodes in the linked list and k is the number of rotations.
// Space Complexity: O(1) as we are using only constant extra space.

//! Optimized Solution
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head;
        int n = 1;
        while(tail->next){
            tail = tail->next;
            n++;
        }
        k = k % n;
        if(k == 0) return head;
        tail->next = head;
        ListNode* temp = head;
        for(int i=0; i<n-k-1; i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as we are using only constant extra space.