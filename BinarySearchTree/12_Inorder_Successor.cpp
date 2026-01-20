//? Inorder Successor in a BST 
class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *x) {
        int suc = -1;
        Node* node = root;
        int val = x->data;
        while(node != NULL){
            int curr = node->data;
            if(curr > val){
                suc = curr;
                node = node->left;
            }
            else node = node->right;
        }
        return suc;
    }
};
// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(1)