bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, int> mpp;
    ListNode* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp]++;
        temp = temp->next;
    }
    return false;
}
// Time Complexity (TC): O(N)
// Space Complexity (SC): O(N)

//* Tortoise and Hare Algorithm
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
// Time Complexity (TC): O(N)
// Space Complexity (SC): O(1)