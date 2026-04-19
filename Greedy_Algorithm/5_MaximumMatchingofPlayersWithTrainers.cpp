class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int numP = players.size();
        int numT = trainers.size();
        int cnt = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0;
        while(i < numP && j < numT){
            if(players[i] <= trainers[j]){
                cnt++;
                i++, j++;
            }
            else if(players[i] > trainers[j]){
                j++;
            }
        }
        return cnt;
    }
};
// Time Complexity: O(nlogn + mlogm + n + m) where n is the size of players and m is the size of trainers.
// Space Complexity: O(1)

//* Same as Assign Cookies problem, just different variable names and context.