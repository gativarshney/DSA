int lengthOfLoop(Node *head) {
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(mpp.find(temp) != mpp.end()){
            return cnt - mpp[temp];
        }
        mpp[temp] = cnt;
        temp = temp->next;
    }
    return 0;
}

//*Using Tortoise and Hare method (Optimal)
int findLen(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLen(slow, fast);
        }
    }
    return 0;
}