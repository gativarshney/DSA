class Solution {
private:
    void solve(int node, int n, vector<vector<int>> &graph, vector<int> &output, vector<vector<int>> &ans){
        if(node == n-1){
            ans.push_back(output);
            return;
        }
        for(auto &it : graph[node]){
            output.push_back(it);
            solve(it, n, graph, output, ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> parent(n);
        vector<vector<int>> ans;
        vector<int> output;
        output.push_back(0);
        solve(0, n, graph, output, ans);
        return ans;
    }
};