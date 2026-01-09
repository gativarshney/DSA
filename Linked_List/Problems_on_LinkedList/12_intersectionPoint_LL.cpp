 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp = headA;
    ListNode* temp = headB;
    unordered_map<ListNode*, int> mpp;
    while(temp != nullptr){
        mpp[temp] = 1;
        temp = temp->next;
    }
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
//? TC: O(m + n) SC: O(n) or O(m)

//************************************************ */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* t1 = headA;
    ListNode* t2 = headB;
    int n1 = 0, n2 = 0;
    while(t1 != nullptr){
        n1++;
        t1 = t1->next;
    }
    while(t2 != nullptr){
        n2++;
        t2 = t2->next;
    }
    t1 = headA;
    t2 = headB;
    if(n1 > n2){
        for(int i=1; i<= (n1-n2); i++){
            t1 = t1->next;
        }
    }
    else{
        for(int i=1; i<= (n2-n1); i++){
            t2 = t2->next;
        }
    }
    while(t1 != nullptr || t2 != nullptr){
        if(t1 == t2) return t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return nullptr;
}
//? TC: O(n1 + 2 * n2) or O(2 * n1 + n2)
//? SC: O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr) return nullptr;
    ListNode* t1 = headA;
    ListNode* t2 = headB;
    
    while(t1 != t2){
        t1 = (t1 == nullptr)? headB : t1->next;
        t2 = (t2 == nullptr)? headA : t2->next;
    }
    return t1;
}

//? TC: O(n1 + n2) SC: O(1)