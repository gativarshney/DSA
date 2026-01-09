// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

ListNode* middleNodeBruteForce(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    int mid = cnt/2 + 1;
    temp = head;
    while(temp != NULL){
        cnt--;
        if(mid == 0) break;
        temp = temp->next;
    }
    head = temp;
    return head;
}
//* TC : O(N + N/2)

//! Tortoise and Hare (Optimal solution)
ListNode* middleNodeOptimal(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//* TC : O(N/2) SC: O(1)