//? Inorder Predecessor in a BST
class Solution {
  public:
    int inOrderPredecessor(Node *root, Node *x) {
        int pre = -1;
        Node* node = root;
        int val = x->data;
        while(node != NULL){
            int curr = node->data;
            if(curr < val){
                pre = curr;
                node = node->right;
            }
            else node = node->left;
        }
        return pre;
    }
};
// Time Complexity: O(h) where h is the height of the tree  
// Space Complexity: O(1)