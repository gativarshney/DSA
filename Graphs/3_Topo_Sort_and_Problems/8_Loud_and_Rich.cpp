class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto &it : richer){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = i;
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(quiet[ans[u]] < quiet[ans[v]]){
                    ans[v] = ans[u];
                }
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return ans;
    }
};
// Time Complexity: O(n + m) where n is the number of people and m is the number of richer relationships.
// Space Complexity: O(n + m) for the adjacency list and indegree array.

