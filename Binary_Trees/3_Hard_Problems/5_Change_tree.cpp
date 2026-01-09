class Solution{
    void changeTree(Node* root){
        if(root == NULL) return;
        int childsValue = 0;
        if(root->left) childsValue += root->left->val;
        if(root->right) childsValue += root->right->val;

        if(root->val < childsValue) root->val = childsValue;
        else {
            if(root->left) root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }
        changeTree(root->left);
        changeTree(root->right);
        
        int total = 0;
        if(root->left) total += root->left->val;
        if(root->right) total += root->right->val;
        if(root->left || root->right) root->val = total;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to recursive stack