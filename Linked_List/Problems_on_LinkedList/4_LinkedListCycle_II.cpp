// Linked List Cycle II
//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.

ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode*, int> mpp;
    ListNode* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}
// TC: O(N) SC: O(N

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
// TC: O(N) SC: O(1)

//? Distance from head to cycle start = distance from meeting point to cycle start (mod cycle)

//! Explanation for Interview
/*
After detecting a cycle, when slow and fast meet, I reset one pointer to the head.
Then I move both pointers one step at a time.
Due to the distance relationship between head, cycle start, and meeting point, both pointers will meet exactly at the start of the cycle.
This works because the distance from head to cycle start is equal to the distance from meeting point to cycle start, so they will synchronize at the cycle start.

Distance Relationship:
Let’s say:
- Distance from head to cycle start = L
- Distance from cycle start to meeting point = x
- Distance from meeting point back to cycle start = C - x (where C is the cycle length)

When they meet, the fast pointer has traveled twice the distance of the slow pointer, so:
2(L + x) = L + x + kC
2L + 2x = L + x + kC
L + x = kC
L = kC - x

The fast pointer may complete multiple cycles before meeting the slow pointer, so we use kC instead of just C. This leads to the relation L + x = kC, which explains why resetting one pointer to head works.
*/