ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* curr = dummyNode;
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int carry = 0;
    while(t1 != nullptr || t2 != nullptr){
        int value = ((t1 == nullptr) ? 0 : t1->val) + ((t2 == nullptr) ? 0 : t2->val) + carry;
        ListNode* newNode = new ListNode(value % 10);
        carry = value / 10;
        curr->next = newNode;
        curr = curr->next;
        
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

// TC: O(max(n1, n2))
// SC: O(max(n1, n2)) --> used to store final answer so it can't be optimised further