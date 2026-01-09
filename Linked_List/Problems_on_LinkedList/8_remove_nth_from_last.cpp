ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
    ListNode* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    if(n == cnt){
        ListNode* curr = head;
        head = head->next;
        delete(curr);
        return head;
    }
    temp = head;
    int ind = cnt - n;
    while(temp != nullptr){
        ind--;
        if(ind == 0) break;
        temp = temp->next;
    }
    ListNode* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete(deleteNode);
    return head;
}
//TC: O(len) + O(len - n)

//Optimal
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    if(fast == nullptr){
        ListNode* newHead = head->next;
        delete(head);
        return newHead;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete(deleteNode);
    return head;
}
//TC: O(len) SC:O(1)