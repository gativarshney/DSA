class Solution {
public:
        //* Can you find a valid path whose minimum edge is at least limit and the total weight is at most k?
    bool check(int limit, vector<vector<pair<int,int>>>& adj, vector<int>& topo, vector<bool>& online, long long k, int n){

        long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for(int u : topo){

            if(dist[u] == INF)
                continue;

            if(u != 0 && u != n-1 && online[u] == false)
                continue;

            for(auto edge : adj[u]){

                int v = edge.first;
                int wt = edge.second;

                if(wt < limit)
                    continue;

                if(v != 0 && v != n-1 && online[v] == false)
                    continue;

                if(dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);
        vector<int> weights;

        for(auto e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            indegree[v]++;

            weights.push_back(w);
        }

        // Topological Sort
        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){

            int node=q.front();
            q.pop();

            topo.push_back(node);

            for(auto x:adj[node]){

                int nxt=x.first;

                indegree[nxt]--;

                if(indegree[nxt]==0)
                    q.push(nxt);
            }
        }

        // Remove duplicate weights
        sort(weights.begin(), weights.end());

        vector<int> uniqueWeights;

        for(int x : weights){

            if(uniqueWeights.empty() || uniqueWeights.back()!=x)
                uniqueWeights.push_back(x);
        }

        int low = 0;
        int high = uniqueWeights.size()-1;
        int ans = -1;

        while(low <= high){

            int mid=(low+high)/2;

            if(check(uniqueWeights[mid], adj, topo, online, k, n)){
                ans = uniqueWeights[mid];
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }
};

//* Time Complexity: O(E + V) for topological sort + O(log E * (E + V)) for binary search and check function, where E is the number of edges and V is the number of vertices in the graph.
//* Space Complexity: O(E + V) for adjacency list, indegree array, and topological sort array, where E is the number of edges and V is the number of vertices in the graph.