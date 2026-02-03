class Solution {
private:
    vector<int> topoSort(vector<vector<int>>&adj, vector<int> &present){
        vector<int> topo;
        vector<int> indegree(26, 0);
        queue<int> q;
        for(int i=0; i<26; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<26; i++){
            if(indegree[i] == 0 && present[i]) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int m = min(s1.size(), s2.size());
            if (s1.size() > s2.size() && s1.substr(0, m) == s2) return "";
            for(int j=0; j<m; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> present(26, 0);
        for(int i=0; i<n; i++){
            for(auto ch : words[i]){
                present[ch - 'a'] = 1;
            }
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(present[i] == 1) cnt++;
        }
        vector<int> topo = topoSort(adj, present);
        if(topo.size() != cnt) return "";
        string ans = "";
        for(int i=0; i<topo.size(); i++){
            char ch = topo[i] + 'a';
            ans += ch;
        }
        return ans;
    }
};
// * Time Complexity: O(N * M + V + E) where N is number of words, M is average length of words, V is number of unique characters (at most 26), E is number of edges in the graph.
// * Space Complexity: O(V + E) for adjacency list + O(V) for indegree array + O(V) for present array ~ O(V + E)
//! NOTE: The problem assumes that the input words are sorted according to the alien dictionary order.
//* The function first builds a directed graph based on the order of characters in adjacent words.
//* Then, it performs a topological sort using Kahn's Algorithm to determine the order of characters in the alien language.

//!NOTE: Edge Case Handling
//* If a word like "abc" appears before "ab", it is impossible to determine a valid character order, and the function returns an empty string in such cases.
//* If there is cycle in the graph, it indicates conflicting character orders, and the function returns an empty string as well.