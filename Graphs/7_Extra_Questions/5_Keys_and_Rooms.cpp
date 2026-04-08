class Solution {
private:
    void dfs(int idx, vector<vector<int>> &rooms, vector<int> &vis){
        vis[idx] = 1;
        for(auto it : rooms[idx]){
            if(!vis[it]) dfs(it, rooms, vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, rooms, vis);
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
// Time Complexity: O(N + E) where N is the number of rooms and E is the total number of keys in all rooms.
// Space Complexity: O(N) for the visited array and the recursion stack in the worst case.