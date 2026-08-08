class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int minCost = 0;

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){

                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                pq.push({d, {i, j}});
            }
        }

        DisjointSet ds(n);

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int d = temp.first;
            int u = temp.second.first;
            int v = temp.second.second;

            if(ds.findUPar(u) != ds.findUPar(v)){
                minCost += d;
                ds.unionBySize(u, v);
            }
        }
        
        return minCost;
    }
};