// We use Floyd–Warshall to compute all-pairs shortest paths in O(n³) time, updating the adjacency matrix in place by considering every node as an intermediate vertex.
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 1e8;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INF || dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

//? Time Complexity: O(n^3) where n is the number of vertices in the graph.
//? Space Complexity: O(n^2) because we are using input matrix to store distances between every pair of vertices but is taking space in our result so we will consider it in space complexity. Otherwise, no extra space is used.

// If check for negative weight cycles is needed, we can add the following after the main loops:
for(int i=0; i<n; i++){
    if(dist[i][i] < 0){
        // Negative weight cycle detected    
    }
}
// As a negative weight cycle will result in a negative value on the diagonal of the distance matrix, which is not possible in a graph without such cycles.

// Because Floyd-Warshall keeps relaxing paths, and a negative cycle allows reducing the distance from a node to itself indefinitely, which reflects as a negative diagonal value.