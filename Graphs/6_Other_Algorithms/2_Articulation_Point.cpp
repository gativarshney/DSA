class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int> adj[], unordered_set<int>&st, vector<int>&vis, vector<int>&inTime, vector<int>&low){
        vis[node] = 1;
        inTime[node] = low[node] = timer++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, adj, st, vis, inTime, low);
                low[node] = min(low[node], low[it]);
                if(low[it] >= inTime[node] && parent != -1){
                    st.insert(node);
                }
                child++;
            }
            else{
                low[node] = min(low[node], inTime[it]);
            }
        }
        // Back edge
        if(parent == -1 && child > 1) {
            st.insert(node);
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        unordered_set<int> st;
        vector<int> vis(V, 0);
        vector<int> inTime(V);
        vector<int> low(V);
        vector<int> ans;
        dfs(0, -1, adj, st, vis, inTime, low);
        if(st.size() == 0) return {-1};
        for(auto it : st) ans.push_back(it);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V) for the visited array, inTime array, low array, and the recursion stack in the worst case.

//!NOTE:
// The condition: root is articulation if child > 1 means:
// There are multiple independent DFS branches starting from root. If those branches were connected to each other, they would not appear as separate children in DFS. Simply then child = 1 will happen as all nodes will traverse in a single dfs call. But if there are multiple independent branches, then child > 1 will happen and root will be an articulation point.

//* low[it] >= inTime[node] means : The subtree rooted at 'it' cannot reach any ancestor of 'node'. So the only way that subtree connects to the rest of the graph is through node. Thus, removing node disconnects that subtree. So node is an articulation point.
//* Root node has a separate rule: Root is articulation point if it has more than one DFS child.
