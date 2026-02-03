class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt == V) return false;
        return true;
    }
};
//* Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
//* Space Complexity: O(V) + O(V) + O(V + E) for the indegree array, queue, and adjacency list.

//! NOTE: This implementation uses Kahn's Algorithm (BFS) to detect a cycle in a directed graph. If the count of nodes processed is less than the total number of nodes, it indicates the presence of a cycle.