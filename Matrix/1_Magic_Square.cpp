class Solution {
private: 
    bool magicSquare(vector<vector<int>>& grid, int r, int c){
        vector<int> freq(10, 0);
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                int num = grid[i][j];
                if(num < 1 || num > 9) return false;
                freq[num]++;
                if(freq[num] > 1) return false;
            }
        }
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i=0; i<3; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
        }
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m < 3 || n < 3) return 0;
        int cnt = 0;
        for(int i=0; i <= m - 3; i++){
            for(int j=0; j <= n-3; j++){
                if(magicSquare(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};


//* TC: O((M-2)*(N-2)) ~ O(M*N)
//* SC: O(1)

//! magicSquare() work per subgrid = O(1)
// Everything inside checks a fixed 3×3 grid:
// Frequency check → 9 cells
// Row sums → 3
// Column sums → 3
// Diagonals → 2
// All of this is constant work.
// ➡️ O(1) per subgrid