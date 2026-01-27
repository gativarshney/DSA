//? Pythagorean Distance Nodes in a Tree
// You are also given three distinct target nodes x, y, and z. The node u is called special if the three distances form a Pythagorean Triplet.
class Solution {
private:
    bool pytha(long long a, long long b, long long c){
        vector<long long> v = {a, b, c};
        sort(v.begin(), v.end());
        return v[0]*v[0] + v[1]*v[1] == v[2]*v[2];
    }
    vector<int> bfs(int src, vector<vector<int>> &adj){
        int n = adj.size();
        queue<int> q;
        vector<int> dist(n, -1);
        
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int it : adj[node]){
                if(dist[it] == -1){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist;        
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dx = bfs(x, adj);
        vector<int> dy = bfs(y, adj);
        vector<int> dz = bfs(z, adj);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(dx[i] == -1 || dy[i] == -1 || dz[i] == -1) continue;
            if(pytha(dx[i], dy[i], dz[i])) cnt++;
        }
        return cnt;
    }
}
//! NOTE:
//* Time Complexity: Each BFS runs in O(N + E). Since BFS is performed three times (from nodes x, y, and z), the total time complexity is O(3·(N + E)), which simplifies to O(N + E).

//* Space Complexity: O(N + E) due to the adjacency list, distance arrays (dx, dy, dz), and the queue used during BFS traversal.

//* This solution efficiently identifies all special nodes by precomputing distances from x, y, and z using BFS and then checking for a Pythagorean triplet for each node.

//? Instead of performing BFS from every node (which would be O(N·(N + E))), 
//? we optimize the solution by running BFS only three times from the fixed nodes x, y, and z.
