class Solution {
private:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, st);
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
//* Time Complexity: O(V + E)
//* Space Complexity: O(V) for visited array + O(V) for stack + O(V) for recursion stack ~ O(V) but for adjacency list O(V + E)

//! NOTE: Topological Sort is only applicable for Directed Acyclic Graphs (DAGs).
//* In Topological Sort, for every directed edge u -> v from vertex u to vertex v, u comes before v in the ordering. 
//? If the graph contains a cycle, a valid topological ordering is not possible.
//? The above implementation does not include cycle detection. If needed, cycle detection can be implemented using Kahn's Algorithm or by modifying the DFS approach.
//? Topological Sort has various applications including scheduling tasks, resolving symbol dependencies in linkers, and determining the order of compilation tasks.