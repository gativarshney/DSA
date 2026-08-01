class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> start, ending;

        for(int i = 0; i < n; ) {
            if(s[i] == '0') {
                int j = i;
                while(j < n && s[j] == '0') j++;
                start.push_back(i);
                ending.push_back(j - 1);
                i = j;
            }
            else {
                i++;
            }
        }

        int m = start.size();

        int ones = 0;
        for(char ch : s) {
            if(ch == '1') ones++;
        }

        auto getLen = [&](int idx) {
            return ending[idx] - start[idx] + 1;
        };

        int sz = (m >= 2 ? m - 1 : 0);

        vector<int> lg(max(sz, 1) + 1);

        for(int i = 2; i <= sz; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        vector<vector<int>> st;

        if(sz > 0) {
            int k = lg[sz] + 1;

            st.assign(k, vector<int>(sz));

            for(int i = 0; i < sz; i++) {
                st[0][i] = getLen(i) + getLen(i + 1);
            }

            for(int j = 1; j < k; j++) {
                for(int i = 0; i + (1 << j) <= sz; i++) {
                    st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        auto query = [&](int l, int r) {
            if(l > r || sz == 0) return 0;

            int j = lg[r - l + 1];

            return max(st[j][l], st[j][r - (1 << j) + 1]);
        };

        vector<int> ans;

        for(auto &it : queries) {
            int l = it[0];
            int r = it[1];

            int gain = 0;

            int left = 0;
            int right = m - 1;
            int first = m;

            while(left <= right) {
                int mid = (left + right) / 2;

                if(ending[mid] >= l) {
                    first = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            left = 0;
            right = m - 1;

            int last = -1;

            while(left <= right) {
                int mid = (left + right) / 2;

                if(start[mid] <= r) {
                    last = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            if(first <= last && first < m && last >= 0 && last - first >= 1) {
                auto clippedLen = [&](int idx) {
                    return min(ending[idx], r) - max(start[idx], l) + 1;
                };

                gain = max(gain, query(first + 1, last - 2));

                gain = max(gain, clippedLen(first) + ((first + 1 == last) ? clippedLen(first + 1) : getLen(first + 1)));

                if(last - 1 >= first) {
                    gain = max(gain, ((last - 1 == first) ? clippedLen(last - 1) : getLen(last - 1)) + clippedLen(last));
                }
            }

            ans.push_back(ones + gain);
        }

        return ans;
    }
};