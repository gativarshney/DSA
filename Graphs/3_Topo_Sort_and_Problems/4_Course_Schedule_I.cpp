class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        if(cnt == numCourses) return true;
        return false;
    }
};
//? Time Complexity: O(V + E)
//? Space Complexity: O(V) + O(V) + O(V + E) for the indegree array, queue, and adjacency list.

//! NOTE: This implementation uses Kahn's Algorithm (BFS) to determine if all courses can be finished. If the count of courses that can be completed is equal to the total number of courses, it indicates that there are no cycles in the prerequisite graph, allowing all courses to be finished.
