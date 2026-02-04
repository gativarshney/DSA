//* Bellman Ford Algorithm helps to detect negative cycles in a graph and also helps to find the shortest path from a source vertex to all other vertices in the graph. It is an improvement over Dijkstra's algorithm as it can handle negative weight edges.
//* Bellman algo works for directed graphs and can also be used for undirected graphs by treating them as directed graphs with edges in both directions.
//* The algorithm works by relaxing all the edges in the graph |V| - 1 times, where |V| is the number of vertices in the graph. After |V|-1 iterations, if we can still relax any edge, then there is a negative weight cycle in the graph.
//* Why N-1 iterations? Since in a graph of N nodes, in worst case, you will take N-1 edges to reach from the first to the last, thereby we iterate for N-1 iterations. Try drawing a graph which takes more than N-1 edges for any path, it is not possible.

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i=0; i<V-1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};

//? Time Complexity: O(V * E) where V is the number of vertices and E is the number of edges in the graph.
//? Space Complexity: O(V) for the distance array.