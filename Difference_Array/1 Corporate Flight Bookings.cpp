class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> d(n + 2, 0);

        for(int i = 0; i < bookings.size(); i++){
            int s = bookings[i][0];
            int e = bookings[i][1];
            int x = bookings[i][2];

            d[s] += x;
            d[e + 1] -= x;
        }

        vector<int> ans(n);

        ans[0] = d[1];

        for(int i = 1; i < n; i++){
            ans[i] = ans[i - 1] + d[i + 1];
        }

        return ans;
    }
};

// 1 indexed array given in the problem statement, so we need to use n + 2 size for the difference array to handle the edge cases properly. The difference array technique allows us to efficiently apply range updates and compute the final values in linear time.
