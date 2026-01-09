//Brute Force
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> iKnow(n, 0);
        vector<int> knowsMe(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && mat[i][j] == 1){
                    iKnow[i]++;
                    knowsMe[j]++;
                }
            } 
        }
        for(int k=0; k<n; k++){
            if(iKnow[k] == 0 && knowsMe[k] == n-1){
                return k;
            }
        }
        return -1;
    }
};
// TC: O(N^2) SC: O(2 * N)

//? Optimized Approach
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n-1;
        while(top < down){
            if(top!=down && mat[top][down] == 1) top++;
            else if(top!=down && mat[down][top] == 1) down--;
            else top++, down--;
        }
        if(top > down) return -1;
        for(int i=0; i<n; i++){
            if(i == top) continue;
            if(mat[top][i] == 1 || mat[i][top] == 0) return -1;
        }
        return top;
    }
};
// TC: O(N) SC: O(1)