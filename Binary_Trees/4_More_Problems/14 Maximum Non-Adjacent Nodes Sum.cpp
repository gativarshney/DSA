class Solution {
    pair<int, int> solve(Node* node){
        if(!node) return {0, 0};
        
        pair<int, int> left = solve(node->left);
        pair<int, int> right = solve(node->right);
        
        int includeCurr = node->data + left.second + right.second;
        int excludeCurr = max(left.first, left.second) + max(right.first, right.second);
        
        return {includeCurr, excludeCurr};
    }
  public:
    int getMaxSum(Node *root) {
        pair<int, int> ans = solve(root);
        
        return max(ans.first, ans.second);
        
    }
};
// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree, due to the recursive call stack. In the worst case (skewed tree), H can be O(N).