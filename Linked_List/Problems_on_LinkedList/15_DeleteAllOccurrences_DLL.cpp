// Delete all occurrences of a given key in a doubly linked list
Node * deleteAllOccurrences(Node* head, int k) {
    if(head == nullptr || (head->next == nullptr && head->data == k)) return nullptr;
        Node* temp = head;
        Node* prevNode = nullptr;
        Node* frontNode = nullptr;
        Node* deleteNode = nullptr;
        while(temp != nullptr){
            if(temp->data == k){
                if(head->data == k){
                    head = head->next;
                }
                prevNode = temp->prev;
                frontNode = temp->next;
                if(prevNode) prevNode->next = frontNode;
                if(frontNode) frontNode->prev = prevNode;
                deleteNode = temp;
                delete(deleteNode);
                temp = frontNode;
            } 
            else temp = temp->next;
        }
    return head;
}