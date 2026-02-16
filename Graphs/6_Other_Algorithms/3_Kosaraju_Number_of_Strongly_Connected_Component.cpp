//! Using Kosaraju's Algorithm
class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, st);
        }
        st.push(node);
    }
    void traverse(int node, vector<vector<int>> &revAdj, vector<int> &vis){
        vis[node] = 1;
        for(auto it : revAdj[node]){
            if(!vis[it]) traverse(it, revAdj, vis);
        }
    }
public:
    int kosaraju(vector<vector<int>> &adj) {
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
        int cnt = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                traverse(node, revAdj, vis);
            }
        }
        return cnt;
    }
};
//* Time Complexity: O(V + E) + O(V + E) + O(V + E) ~ O(V + E)
//* Space Complexity: O(V) + O(V) + O(V) ~ O(V)

//? Kosaraju works because finishing times ensure we process SCCs in correct topological order, and reversing edges prevents DFS from escaping its own SCC.

//! Kosaraju's Algorithm 
// 1. Sort the nodes in decreasing order of their finishing times using DFS and store them in a stack.
// 2. Reverse the graph.
// 3. Pop the nodes from the stack and perform DFS on the reversed graph. Each DFS call will give you one strongly connected component. Count the number of DFS calls to get the number of strongly connected components.

//! Kosaraju's Algorithm in detail (Strongly Connected Components)

// 1. Perform DFS on the original graph.
//    Push nodes into a stack in order of their finishing times.
//    (Node with highest finishing time will be on top.)

// 2. Reverse the graph (reverse all edges).

// 3. Pop nodes from the stack one by one.
//    If a node is not visited in the reversed graph,
//    perform DFS from it.
//    Each DFS traversal gives exactly one SCC.

// Count the number of such DFS calls → total SCCs.


//! Key Idea:
// If there is a directed edge from SCC A → SCC B,
// then in the DFS of the original graph,
// nodes of SCC A will finish AFTER nodes of SCC B.

// So the node with the largest finishing time
// will belong to a "source SCC" in the condensation graph.

// After reversing the graph,
// all edges between SCCs also reverse direction.
// So when we start DFS from that node,
// we cannot go outside its SCC.
// Hence, each DFS in reversed graph isolates exactly one SCC.

