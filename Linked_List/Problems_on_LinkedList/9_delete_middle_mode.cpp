ListNode* deleteMiddle(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    int res = cnt/2;
    temp = head;
    while(temp != nullptr){
        res--;
        if(res == 0){
            ListNode* middle = temp->next;
            temp->next = temp->next->next;
            delete(middle);
            break;
        }
        temp = temp->next;
    }
    return head;
}
// TC: O(n + n/2) SC: O(1)

//OPtimal
ListNode* deleteMiddle(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    fast = fast->next->next; // skip first slow movement
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* middle = slow->next;
    slow->next = slow->next->next;
    delete(middle);
    return head;
    }
// TC: O(n/2)

// optimal approach-2
ListNode* deleteMiddle(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next->next != nullptr && fast->next->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete(deleteNode);
    return head;
}
// TC: O(n/2)