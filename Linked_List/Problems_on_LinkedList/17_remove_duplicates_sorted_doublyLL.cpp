Node *removeDuplicates(struct Node *head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && nextNode->data == temp->data){
            Node* deleteNode = nextNode;
            nextNode = nextNode->next;
            delete(deleteNode);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}
// TC: O(N) {outer while goes for non-duplicates and inner while goes for duplicates sp overall TC = O(N)}
// SC: O(1)