//! Using Tarjan's Algorithm to find Bridges in a Graph
class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &bridges, vector<int> &vis, vector<int> &inTime, vector<int> &low){
        vis[node] = 1;
        inTime[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, adj, bridges, vis, inTime, low);
                // After returning from the DFS call, we update the low value of the current node to the minimum of its current low value and the low value of the neighbor. This is because if the neighbor can reach an ancestor of the current node, then the current node can also reach that ancestor through the neighbor with lower low value.
                low[node] = min(low[node], low[it]);
                // Bridge case: If the low value of the neighbor is greater than the inTime of the current node, it means that there is no back edge from the neighbor to any ancestor of the current node, making the edge between them a bridge. We add this edge to our list of bridges. Simply, there is no way to reach node from it without using the edge between them, so we can say that the edge is a bridge. Otherwise if any back edge exists, then it means it have updated the low value of node to low[it] and we can say that there is a way to reach node from it without using the edge between them, so we can say that the edge is not a bridge.
                if(low[it] > inTime[node]){
                    bridges.push_back({node, it});
                }
            }
            // node already visited and not parent
            // Back edge case: If the neighbor is already visited and is not the parent, then we update the low value of the current node to the minimum of its current low value and the inTime of the neighbor. This is because we can reach an ancestor of the current node through this back edge, which may help in finding bridges.
            else{
                low[node] = min(low[node], inTime[it]);
            }
        }
    }
//* inTime = discovery time of the node
//* low[node] = minimum discovery time reachable from node or its subtree using at most one back-edge

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;
        vector<int> inTime(n);
        vector<int> low(n);
        dfs(0, -1, adj, bridges, vis, inTime, low);
        return bridges;
    }
};
//* Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
//* Space Complexity: O(V + E) for the adjacency list and O(V) for the additional arrays used in the DFS traversal, resulting in an overall space complexity of O(V + E).

//? Note: The above code assumes that the graph is connected and undirected. If the graph is not connected, you may need to run the DFS for each unvisited node to ensure all components are covered.

// Intution: A bridge is an edge that, if removed, would increase the number of connected components in the graph. Tarjan's algorithm uses a depth-first search (DFS) to find these bridges by keeping track of discovery times and low values for each vertex. The discovery time is the time when a vertex is first visited, while the low value represents the earliest visited vertex reachable from the subtree rooted at that vertex. If the low value of a neighboring vertex is greater than the discovery time of the current vertex, it indicates that there is no back edge connecting the neighbor to an ancestor of the current vertex, making the edge between them a bridge.

//* NOTE: in else part we used inTime[it] instead of low[it] because if we take low[it] we may propagate values that do not belong to current subtree path. This will break bridge logic. We only want to consider back edges that connect to ancestors of the current node, which is why we use inTime[it] to update low[node]. This ensures that we are only considering back edges that lead to ancestors and not those that may lead to other parts of the graph.