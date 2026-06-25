class Solution {
    pair<bool, int> solve(Node* node){
        if(node == NULL) return {true, 0};
        
        if(node->left == NULL && node->right == NULL) return {true, node->data};
        
        pair<bool, int> leftAns = solve(node->left);
        pair<bool, int> rightAns = solve(node->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        int sum = leftAns.second + rightAns.second;
        bool condition = node->data == sum;
        
        pair<bool, int> ans;
        if(left && right && condition){
            ans.first = true;
            ans.second = node->data + sum;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        if(root == NULL) return true;
        
        return solve(root).first;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree (due to recursionsion stack)