Node* segregate(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while(temp != nullptr){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else if(temp->data == 2) cnt2++;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}
//* TC: O(2*N) SC:O(1)


Node* segregate(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* temp = head;
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    
    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        } else if(temp->data == 1){
            one->next = temp;
            one = temp;
        } else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    Node* newHead = zeroHead->next;
    delete(zeroHead), delete(oneHead), delete(twoHead);
    return newHead;
}
// * TC: O(N) SC:O(1)