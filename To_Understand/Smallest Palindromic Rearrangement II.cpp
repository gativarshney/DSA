class Solution {
public:
    const int MAX = 1000001;

    int nCk(int n, int k) {
        if (k > n) {
            return 0;
        }

        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;

            if (res >= MAX) {
                return MAX;
            }
        }

        return (int)res;
    }

    int countWays(vector<int>& cnt) {
        int total = 0;

        for (int x : cnt) {
            total += x;
        }

        long long ans = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) {
                continue;
            }

            ans *= nCk(rem, x);

            if (ans >= MAX) {
                return MAX;
            }

            rem -= x;
        }

        return (int)ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] % 2) {
                mid += char('a' + i);
            }
        }

        if (countWays(half) < k) {
            return "";
        }

        int len = 0;

        for (int x : half) {
            len += x;
        }

        string left = "";

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) {
                    continue;
                }

                half[c]--;

                int ways = countWays(half);

                if (ways >= k) {
                    left += char('a' + c);
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};