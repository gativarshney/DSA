class Solution {
  private:
    Node* findTargetNode(Node* root, int target){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* node = q.front();
            q.pop();
            if(node->data == target) return node;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return NULL;
    }
    void parentNode(Node* root, unordered_map<Node*, Node*> &parentMap){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* current = q.front();
                q.pop();
                if(current->left){
                    parentMap[current->left] = current;
                    q.push(current->left);
                }
                if(current->right){
                    parentMap[current->right] = current;
                    q.push(current->right);
                }
            }
        }
    }
  public:
    int minTime(Node* root, int target) {
        if(root == NULL) return 0;
        Node* targetNode = findTargetNode(root, target);
        if(targetNode == NULL) return 0;
        unordered_map<Node*, Node*> parentMap;
        parentNode(root, parentMap);
        int time = 0;
        queue<Node*> q;
        q.push(targetNode);
        unordered_map<Node*, bool> visited;
        visited[targetNode] = true;
        while(!q.empty()){
            bool burned = false;
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                    burned = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                    burned = true;
                }
                if((parentMap.find(node) != parentMap.end()) && (!visited[parentMap[node]])){
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                    burned = true;
                }
            }
            if(burned) time++;
        }
        return time;
    }
};
//Time Complexity: O(N), where N is the number of nodes in the binary tree. We traverse each node once to build the parent map and once more during the burning process.
// Space Complexity: O(N) for the parent map and the visited map.