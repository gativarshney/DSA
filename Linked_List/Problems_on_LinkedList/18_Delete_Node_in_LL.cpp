//! Write a function to delete a node (except the tail) in a singly linked list, given only access to that node. ie. Head is not given and we have to delete the node which is given as input.

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