class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        while(nextNode->next != NULL){
            node->val = nextNode->val;
            node = nextNode;
            nextNode = nextNode->next;
        }
        if(nextNode->next == NULL){
            node->val = nextNode->val;
            node->next = NULL;
        }
    }
};
// TC: O(N) in worst case when the node to be deleted is the second last node, SC: O(1)

//! Optimal Solution
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// TC: O(1) SC: O(1)