Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = nullptr;
    while(temp != nullptr){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node* addOne(Node* head) {
    head = reverse(head); // O(N)
    Node* temp = head;
    int carry = 1;
    while(temp != nullptr){     // O(N)
        temp->data = temp->data + carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    head = reverse(head);   // O(N)
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        head = newHead;
    }
    return head;
}
//? TC: O(3 * N)  SC:O(1)

//! Using recursion
int helper(Node* temp){
    if(temp == nullptr) return 1;
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}
Node* addOne(Node* head) {
    int carry = helper(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head; 
}
//? TC: O(N) SC: O(N)