class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) != mpp.end()){
                    int index = mpp[mail];
                    ds.unionBySize(i, index);
                }
                else{
                    mpp[mail] = i;
                }
            }
        }
        vector<vector<string>> ans(n);
        vector<vector<string>> res;
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            ans[node].push_back(mail);
        }
        for(int i=0; i<ans.size(); i++){
            if(ans[i].size() == 0) continue;
            else{
                sort(ans[i].begin(), ans[i].end());
                vector<string> temp;
                temp.push_back(accounts[ds.findUPar(i)][0]);
                for(auto it : ans[i]) temp.push_back(it);
                res.push_back(temp);
            }
        }
        return res;
    }
};

//* Time Complexity: O(E + ElogE) for iterating through the accounts and performing union-find operations where E is the total number of email addresses across all accounts, and sorting the email addresses for each merged account.
//* Space Complexity: O(N + E) for the Disjoint Set data structure and the unordered map to store the email addresses and their corresponding account indices, where N is the number of accounts and E is the total number of email addresses or links between name and email addresses.
