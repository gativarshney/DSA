//* Maximum Width of Binary Tree
class Solution {
private: 
    void traverse(TreeNode* root, vector<vector<pair<TreeNode*, long long>>> &arr){
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        while(!q.empty()){
            int n = q.size();
            vector<pair<TreeNode*, long long>> temp;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front().first;
                long long index = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, index*2});
                if(node->right) q.push({node->right, index*2 + 1});
                temp.push_back({node, index});
            }
            arr.push_back(temp);
        }    
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<pair<TreeNode*, long long>>> arr;
        traverse(root, arr);
        int n = arr.size();
        int maxWidth = 0;
        for(int i=0; i<n; i++){
            vector<pair<TreeNode*, long long>> temp = arr[i];
            long long firstIndex = temp[0].second;
            long long lastIndex = temp.back().second;
            int ans = lastIndex - firstIndex + 1;
            maxWidth = max(maxWidth, ans);
        }
        return maxWidth;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)


//! Optimal Approach
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(!q.empty()){
            int n = q.size();
            long long mini = q.front().second;
            long long first, last;
            for(int i=0; i<n; i++){
                long long currIdx = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = currIdx;
                if(i == n-1) last = currIdx;
                if(node->left) q.push({node->left, currIdx*2 + 1});
                if(node->right) q.push({node->right, currIdx*2 + 2});
            }
            int ans = last - first + 1;
            maxWidth = max(maxWidth, ans);
        }
        return maxWidth;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(W), and in the worst case SC: O(N)
// W is the maximum width of the binary tree at any level, N is the number of nodes in the binary tree.