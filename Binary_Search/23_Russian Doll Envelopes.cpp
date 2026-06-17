class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a < b;
        });

        vector<int> temp;
        temp.push_back(envelopes[0][1]);

        for(int i = 1; i < n; i++){

            int h = envelopes[i][1];

            if(h > temp.back()){
                temp.push_back(h);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), h) - temp.begin();
                temp[idx] = h;
            }
        }

        return temp.size();
    }
};