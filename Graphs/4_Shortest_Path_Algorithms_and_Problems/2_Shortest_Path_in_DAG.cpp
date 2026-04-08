class Solution {
private:
    void topoSort(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!vis[v]) topoSort(v, adj, vis, st);
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        // build graph
        for(int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        // topo sort
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) topoSort(i, adj, vis, st);
        }
        // shortest path
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;    // source is vertex 0

        while(!st.empty()) {    // O(V + E)
            int node = st.top();
            st.pop();
            if(dist[node] == INT_MAX) continue;
            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        // mark unreachable
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

//? Given: Source is Vertex 0.
//* Time Complexity: O(V + E) for topo sort + O(V + E) for shortest path calculation = O(V + E)
//* Space Complexity: O(V + E) for adjacency list + O(V) for visited array + O(V) for stack + O(V) for distance array

//! Intuition: (Important Concept)
//! Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it. 
//! Processing the vertices in topological order ensures that by the time you get to a vertex, you've already processed all the vertices that can precede it.
//! Dijkstra's algorithm is necessary for graphs that can contain cycles, because they can't be topologically sorted.