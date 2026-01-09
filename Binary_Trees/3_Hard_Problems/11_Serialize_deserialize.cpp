//* Serialize and Deserialize Binary Tree
#include<bits/stdc++.h>
using namespace std;
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else{
                s.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
// Time Complexity: O(N) for both serialization and deserialization, where N is the number of nodes in the binary tree.
// Space Complexity: O(N) for both serialization and deserialization, due to the storage of the serialized string and the queue used during the processes.