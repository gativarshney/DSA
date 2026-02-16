class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //? Bob's path from his starting node to the root node (0)
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({bob, 0});
        vis[bob] = 1;
        vector<int> bobPath;
        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i] = i;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node == 0){
                while(parent[node] != node){
                    bobPath.push_back(node);
                    node = parent[node];
                }
                bobPath.push_back(bob);
                reverse(bobPath.begin(), bobPath.end());
                break;
            }
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it, steps+1});
                    vis[it] = 1;
                    parent[it] = node;
                }
            }
        }
        
        unordered_map<int, int> mpp;
        for(int i=0; i<bobPath.size(); i++){
            mpp[bobPath[i]] = i;
        }
        int maxIncome = INT_MIN;
        vector<int> visited(n, 0);
        queue<pair<int, pair<int, int>>> q1;
        q1.push({0, {0, amount[0]}});
        while(!q1.empty()){
            int node = q1.front().first;
            int timer = q1.front().second.first;
            int income = q1.front().second.second;
            q1.pop();
            if(node != 0 && adj[node].size() == 1) maxIncome = max(maxIncome, income);
            for(auto it : adj[node]){
                int newIncome = income;
                int time = timer+1;
                if(!visited[it]){
                    if(mpp.find(it) != mpp.end()){
                        int bobSteps = mpp[it];
                        if(time == bobSteps){
                            newIncome += amount[it] / 2;
                        }
                        else if(time < bobSteps){
                            newIncome += amount[it];
                        }
                        // if(timer+1 > bobSteps) Bob has already taken the money, so we don't add anything to newIncome.
                    }
                    else{
                        // Alice can take the full amount as Bob will never reach this node.
                        newIncome += amount[it];
                    }
                    q1.push({it, {time, newIncome}});
                    visited[it] = 1;
                }
            }
        }
        return maxIncome;
    }
};
//* Time Complexity: O(n) where n is the number of nodes in the tree.
//* Space Complexity: O(n) for the adjacency list and other data structures used.