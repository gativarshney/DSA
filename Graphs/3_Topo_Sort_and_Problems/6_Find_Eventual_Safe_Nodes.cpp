class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n, 0); 
        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
//? Time Complexity: O(V + E)
//? Space Complexity: O(V) + O(V) + O(V + E) for the indegree array, queue, and adjacency list.
//* NOTE: This implementation uses the concept of reversing the graph and applying Kahn's Algorithm (BFS) to find all eventual safe nodes. Nodes that can be reached from terminal nodes (nodes with no outgoing edges) are considered safe. The result is sorted before returning to ensure the nodes are in ascending order.
//? After reversing the graph, we look for nodes with zero indegree (which correspond to terminal nodes in the original graph) and perform a BFS to find all nodes that can reach these terminal nodes.