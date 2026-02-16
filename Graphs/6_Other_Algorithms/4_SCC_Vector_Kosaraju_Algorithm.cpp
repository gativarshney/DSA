class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, st);
        }
        st.push(node);
    }
    void traverse(int node, vector<vector<int>> &revAdj, vector<int> &vis, vector<int> &component){
        vis[node] = 1;
        component.push_back(node);
        for(auto it : revAdj[node]){
            if(!vis[it]) traverse(it, revAdj, vis, component);
        }
    }
public:
    vector<vector<int>> kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        stack<int> st;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        vector<vector<int>> revAdj(n);
        for(int i=0; i<n; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                revAdj[it].push_back(i);
            }
        }
        vector<vector<int>> scc;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                vector<int> component;
                traverse(node, revAdj, vis, component);
                scc.push_back(component);
            }
        }
        return scc;
    }
};