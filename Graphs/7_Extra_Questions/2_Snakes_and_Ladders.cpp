class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flat(n*n + 1);
        vector<int> vis(n*n + 1, 0);
        bool leftToRight = true;
        int idx = 1;
        for(int i=n-1; i>=0; i--){
            if(leftToRight){
                for(int j=0; j<n; j++){
                    flat[idx] = board[i][j];  
                    idx++;  
                }
                leftToRight = false;
            }
            else{
                for(int j=n-1; j>=0; j--){
                    flat[idx] = board[i][j];  
                    idx++;
                }
                leftToRight = true;
            }
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = 1;
        while(!q.empty()){
            int curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(curr == n * n) return steps;
            int start = curr + 1;
            int end = min(curr + 6, n * n);
            for(int i=start; i<=end; i++){
                int next = (flat[i] == -1) ? i : flat[i];
                if(!vis[next]){
                    q.push({next, steps+1});
                    vis[next] = 1;
                }
            }
        }
        return -1;
    }
};
//* Time Complexity: O(n^2) where n is the size of the board. 
//* Space Complexity: O(n^2) 