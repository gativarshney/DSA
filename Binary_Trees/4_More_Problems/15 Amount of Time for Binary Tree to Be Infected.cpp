class Solution {
    TreeNode* findNode(TreeNode* root, int start){
        if(!root) return NULL;
        if(root->val == start) return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->val == start) return node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return NULL;
    }
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp){
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                    mpp[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        TreeNode* startNode = findNode(root, start);

        unordered_map<TreeNode*, TreeNode*> parentNode;
        mapParents(root, parentNode);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        int minutes = 0;

        q.push(startNode);
        vis[startNode] = true;

        while(!q.empty()){
            int n = q.size();
            bool infected = false;

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    infected = true;
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    infected = true;
                    vis[node->right] = true;
                }
                if(parentNode[node] && !vis[parentNode[node]]){
                    q.push(parentNode[node]);
                    infected = true;
                    vis[parentNode[node]] = true;
                }
            }

            if(infected) minutes++;
        }

        return minutes;
    }
};
//* Time Complexity: O(N) + O(N) + O(N) = O(N) for finding the start node, mapping parents, and BFS traversal to infect the tree.
//* Space Complexity: SC = O(N) for the queue and O(N) for the parent mapping, O(N) for the visited map, so overall O(N)