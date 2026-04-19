// Using Hashing, TC: O(N^2), SC: O(N^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n; 
        vector<int> hash(size+1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[0].size(); j++){
                int x = grid[i][j];
                hash[x]++;
            }
        }
        int repeating = -1, missing = -1;
        for(int i=1; i <= size; i++){
            if(hash[i] == 2) repeating = i;
            if(hash[i] == 0) missing = i;
        }
        return {repeating, missing};
    }
};

// Using Maths, TC: O(N^2), SC: O(1)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n; 
        long long s = 0;
        long long sq = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[0].size(); j++){
                long long val = grid[i][j];
                s += val;
                sq += (1LL * val * val);
            }
        }
        long long sn = (1LL * size * (size + 1)) / 2;
        long long eq1 = s - sn; // x - y

        long long sqn = (1LL * size * (size + 1) * (2 * size + 1)) / 6;
        long long eq2 = sq - sqn;   // x^2 - y^2 = (x-y)(x+y) = eq1 * (x+y)
        long long sumxy = eq2 / eq1;    // x + y

        int x = (int)(sumxy + eq1) / 2; // x = (x+y + x-y) / 2 = (sumxy + eq1) / 2
        int y = (int)(sumxy) - x;   // y = (x+y) - x = sumxy - x

        return {x, y};
    }
};

// USing XOR, TC: O(N^2), SC: O(1)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n; 
        int xr = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)grid[0].size(); j++){
                xr = xr ^ grid[i][j];
            }
        }
        for(int i = 1; i <= size; i++){
            xr = xr ^ i;
        }
        int bitNo = 0;
        while((xr & (1 << bitNo)) == 0){
            bitNo++;
        }
        int zero = 0;
        int one = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)grid[0].size(); j++){
                if(grid[i][j] & (1 << bitNo)){
                    one = one ^ grid[i][j];
                }
                else{
                    zero = zero ^ grid[i][j];
                }
            }
        }
        for(int i = 1; i <= size; i++){
            if(i & (1 << bitNo)){
                one = one ^ i;
            }
            else{
                zero = zero ^ i;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == zero) cnt++; 
            }
        }
        if(cnt == 2) return {zero, one};
        return {one, zero};
    }
};
//one -> oneClub, zero -> zeroClub