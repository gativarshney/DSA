bool isPalindrome(ListNode* head) {
    stack<int> st;
    ListNode* temp = head;
    while(temp != nullptr){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(st.top() != temp->val){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}
//* TC: O(2*N) SC: O(N)

//? Optimal Approach

ListNode* reverse(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* nextNode = nullptr;
    while(temp != nullptr){
        nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverse(slow->next);
    ListNode* first = head;
    ListNode* second = newHead;
    while(second != nullptr){
        if(first->val != second->val){
            newHead = reverse(newHead);
            return false;
        } 
        first = first->next;
        second = second->next;
    }
    newHead = reverse(newHead);
    return true;
}
//* TC: O(2*N) SC: O(1)
