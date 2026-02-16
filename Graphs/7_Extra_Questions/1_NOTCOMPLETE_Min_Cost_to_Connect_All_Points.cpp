class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<pair<int, int>, pair<int, int>>>> edges;
        for(int i=0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);
                edges.push_back({dist, {{x1, y1}, {x2, y2}}});
            }
        }
        sort(edges.begin(), edges.end());
        int sum = 0;
        queue<<pair<int, pair<pair<int, int>, pair<int, int>>>> q;
        q.push(edges[0]);
        while(!q.empty()){
            
        }
        return sum;
    }
};

//
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int x = points[0][0], y = points[0][1];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {x, y}});
        int sum = 0, cnt = 0;
        while(!pq.empty()){
            int x1 = pq.top().second.first;
            int y1 = pq.top().second.second;
            int d1 = pq.top().first;
            pq.pop();
            sum += d1;
            cnt++;
            if(cnt == n) break;
            for(auto it : points){
                int x2 = it[0], y2 = it[1];
                if(x2 == x1 && y2 == y1) continue;
                int dist = abs(x2 - x1) + abs(y2 - y1);
                pq.push({dist, {x2, y2}});
            }
        }
        return sum;
    }
};