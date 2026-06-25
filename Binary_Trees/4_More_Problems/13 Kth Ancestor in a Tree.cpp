class Solution {
    Node* solve(Node* root, int &k, int node){
        if(root == NULL) return root;
        
        if(root->data == node) return root;
        
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);
        
        if(leftAns != NULL && rightAns == NULL){
            k--;
            if(k == 0){
                k = 1e9;
                return root;
            }
            return leftAns;
        }
        if(leftAns == NULL && rightAns != NULL){
            k--;
            if(k == 0){
                // Answer lock!
                k = 1e9;
                return root;
            }
            return rightAns;
        }
        
        return NULL;
    }
public:
    int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);
        
        if(!ans || ans->data == node) return -1;
        return ans->data;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree, due to the recursive call stack. In the worst case (skewed tree), H can be O(N).

//* Given: 1 ≤ k ≤ 100 
//* That's why edge case if(ans->data == node) return -1;

