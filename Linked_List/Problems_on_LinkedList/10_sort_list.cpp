ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head; 
    vector<int> arr;
    ListNode* temp = head;
    while(temp != nullptr){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    for(int i=0; i<arr.size(); i++){
        temp->val = arr[i];
        temp = temp->next;
    }
    return head;
}
// TC: O(N * logN * N) SC: O(N)

//*********************************************************************/

ListNode* findMiddle(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head; 
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;
    return dummyNode->next;
}
ListNode* mergeSort(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head; 
    ListNode* middle = findMiddle(head);
    ListNode* leftHead = head;
    ListNode* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return merge(leftHead, rightHead);
}
ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head; 
    return mergeSort(head);
}

// TC: O(logN * (N + N/2)) == O(N*logN)
// SC: O(1)