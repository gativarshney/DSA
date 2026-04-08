class Solution {
    void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, int &cnt) {
        vis[u] = 1;
        cnt++;
        for(auto nbr: adj[u]) {
            if(!vis[nbr]) dfs(nbr, adj, vis, cnt);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i < n; i++){
            int x = bombs[i][0];
            int y = bombs[i][1];
            int r = bombs[i][2];
            for(int j=0; j < n; j++){
                if(i == j) continue;
                int x1 = bombs[j][0];
                int y1 = bombs[j][1];
                long long xSqr = 1LL * (x-x1) * (x-x1);
                long long ySqr = 1LL * (y-y1)* (y-y1);
                long long sideSqr = xSqr + ySqr;
                long long radiusSqr = 1LL * r * r;
                if(sideSqr <= radiusSqr){
                    adj[i].push_back(j);
                }
            }
        }
        int maxi = 0;
        for(int i=0; i < n; i++){
            vector<int> vis(n, 0);
            int cnt = 0;
            if(!vis[i]) dfs(i, adj, vis, cnt);
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};