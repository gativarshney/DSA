//! Iterative Implementation
ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* last = nullptr;
    ListNode* nextNode = nullptr;
    while(temp != NULL){
        nextNode = temp->next;
        temp->next = last;
        last = temp;
        temp = nextNode;
    }
    head = last;
    return head;
}
//* TC: O(N), SC: O(1)

//! Recursive Implementation
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
//* TC: O(N), SC: O(N)