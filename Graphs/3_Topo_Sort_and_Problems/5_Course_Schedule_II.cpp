class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
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
        if(topo.size() == numCourses) return topo;
        return {};
    }
};
//? Time Complexity: O(V + E)
//? Space Complexity: O(V) + O(V) + O(V + E) for the indegree array, queue, and adjacency list.
//* NOTE: This implementation uses Kahn's Algorithm (BFS) to find a valid order of courses. If the size of the topological sort result matches the number of courses, it indicates that all courses can be completed without cycles, and the order is returned. Otherwise, an empty vector is returned to signify that it's not possible to complete all courses.