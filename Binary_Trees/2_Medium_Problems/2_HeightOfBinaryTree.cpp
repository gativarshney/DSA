//! The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.

class Solution {
  public:
    int height(Node* root) {
        queue<Node*>q;
        q.push(root);
        int height = 0;
        while(!q.empty()){
            int n =  q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            height++;
        }
        return height-1;
    }
};

// TC: O(N)
// SC: O(w) where w is the maximum width of the tree

//* Optimized Recursive Approach
class Solution {
  public:
    int height(Node* root) {
        if(root == nullptr) return -1;
        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }
};
// TC: O(N)
// SC: O(H) where H is the height of the tree (due to recursion stack)
// In worst case (skewed tree) O(N))
// In best case (balanced tree) O(log N)