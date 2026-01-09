ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    ListNode* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp != nullptr) arr.push_back(temp->val);
    temp = head->next;
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp != nullptr) arr.push_back(temp->val);
    temp = head;
    for(int i=0; i<arr.size(); i++){
        temp->val = arr[i];
        temp = temp->next;
    }
    return head;
}
//* TC:O(2*N) SC: O(N)

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* odd = head;
    ListNode* evenHead = head->next;
    ListNode* even = evenHead;
    while(even != nullptr && even->next != nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
//* TC: O(N), SC: O(1)