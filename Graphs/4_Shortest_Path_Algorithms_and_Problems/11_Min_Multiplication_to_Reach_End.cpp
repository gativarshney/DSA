class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        queue<pair<int, int>> q;
        q.push({0, start});
        vector<int> vis(100000, 0);
        vis[start] = 1;
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            if(node == end) return steps;
            for(int i=0; i<arr.size(); i++){
                int temp = (int)(node * arr[i]) % mod;
                if(!vis[temp]){
                    q.push({steps+1, temp});
                    vis[temp] = 1;
                }
                if(temp == end) return steps+1;
            }
        }
        return -1;
    }
};
//* Time Complexity: O(N*100000) where N is the size of the array
//* Space Complexity: O(100000) for the visited array and queue
//! This approach uses BFS to find the minimum multiplications needed to reach the end value from the start value using the given array of multipliers.
//? It can also be solved using Dijkstra's algorithm as all edges have the same weight of 1.
//! Prefer BFS over Dijkstra's algorithm in this case for simplicity and efficiency.

//* BFS is preferred here due to its simplicity and efficiency in unweighted graphs.
//! Prefer BFS when all edges have the same weight, as it can be more efficient than Dijkstra's algorithm in such scenarios.


//? Using Dijkstra's Algorithm
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node == end) return steps;
            for(int i=0; i<arr.size(); i++){
                int temp = (int)(node * arr[i]) % mod;
                if(dist[temp] > steps + 1){
                    dist[temp] = steps + 1; 
                    q.push({temp, steps+1});
                }
                if(temp == end) return steps+1;
            }
        }
        return -1;
    }
};