class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
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
};
//* Time Complexity: O(V + E) 
//* Space Complexity: O(V) for indegree array + O(V) for queue + O(V + E) for adjacency list

//! NOTE: Kahn's Algorithm is used for Topological Sorting of a Directed Acyclic Graph (DAG).
//* It works by maintaining a list of nodes with no incoming edges (indegree 0) and repeatedly removing these nodes from the graph while updating the indegrees of their neighbors.
//? If the graph contains a cycle, Kahn's Algorithm will not be able to include all nodes in the topological order, indicating that a valid topological sorting is not possible.