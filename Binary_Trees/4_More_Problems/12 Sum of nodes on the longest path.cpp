class Solution {
    void solve(Node* node, int len, int &maxLen, int sum, int &maxi){
        if(node == NULL) return;
        
        sum += node->data;
        len++;
        
        if(!node->left && !node->right){
            if(len > maxLen){
                maxi = sum;
                maxLen = len;
            }
            else if(len == maxLen){
                maxi = max(maxi, sum);
            }
            return;
        }
        
        solve(node->left, len, maxLen, sum, maxi);
        solve(node->right, len, maxLen, sum, maxi);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        int maxi = INT_MIN;
        int maxLen = 0;
        
        solve(root, 0, maxLen, 0, maxi);
        
        return maxi;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree due to the recursion stack.