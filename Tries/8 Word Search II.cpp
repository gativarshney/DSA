struct Node {
    Node* links[26] = {nullptr};
    string word = "";

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
    Node* root;

    void insert(string& word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->word = word;
    }

    void dfs(int i, int j, Node* node, vector<vector<char>>& board, vector<vector<int>>& vis, vector<string>& ans) {

        int m = board.size(), n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(vis[i][j]) return;

        char ch = board[i][j];
        if(!node->containsKey(ch)) return;

        node = node->get(ch);

        if(!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";
        }

        vis[i][j] = 1;

        dfs(i + 1, j, node, board, vis, ans);
        dfs(i - 1, j, node, board, vis, ans);
        dfs(i, j + 1, node, board, vis, ans);
        dfs(i, j - 1, node, board, vis, ans);

        vis[i][j] = 0;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for(string& w : words) {
            insert(w);
        }

        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<string> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, root, board, vis, ans);
            }
        }

        return ans;
    }
};

// TC: O(m * n * 4^l) where m is the number of rows, n is the number of columns, and l is the length of the longest word in the dictionary. The 4^l factor comes from the fact that in the worst case, we can explore 4 directions for each character in the word.

// SC: O(m * n + l) where m is the number of rows, n is the number of columns, and l is the length of the longest word in the dictionary. The m * n factor comes from the visited array, and the l factor comes from the recursion stack in the worst case.