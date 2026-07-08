class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();

        vector<int> ans(q, 0);
        const long long MOD = 1e9 + 7;

        vector<long long> preNum(n, 0);
        vector<long long> preSum(n, 0);
        vector<long long> cnt(n, 0);
        vector<long long> pow10(n, 0);

        pow10[0] = 1;
        for(int i = 1; i < n; i++) {
            pow10[i] = (1LL * pow10[i - 1] * 10) % MOD;
        }

        int firstDigit = s[0] - '0';

        if(firstDigit != 0) {
            preNum[0] = firstDigit;
            preSum[0] = firstDigit;
            cnt[0] = 1;
        }

        for(int i = 1; i < n; i++){
            int digit = s[i] - '0';

            if(digit > 0){
                preNum[i] = (1LL * preNum[i-1] * 10 + digit) % MOD;
                preSum[i] = preSum[i-1] + digit;
                cnt[i] = cnt[i-1] + 1;
            }
            else{
                preNum[i] = preNum[i-1];
                preSum[i] = preSum[i-1];
                cnt[i] = cnt[i-1];
            }
        }

        for(int i = 0; i < q; i++){
            int l =  queries[i][0];
            int r =  queries[i][1];
            int lenOfNum = cnt[r] - (l > 0 ? cnt[l-1] : 0);

            long long num = preNum[r];
            if(l > 0){
                num = (num - (1LL * preNum[l - 1] * pow10[lenOfNum]) % MOD + MOD) % MOD;
            }

            long long sum = preSum[r] - (l > 0 ? preSum[l - 1] : 0);

            long long temp = (1LL * sum * num) % MOD;
            int t = temp % MOD;

            ans[i] = t;
        }

        return ans;
    }
};

//* Preprocessing: O(n)
//* Each query: O(1)
//* Total Time Complexity: O(n + q)

//* Space Complexity: O(n) for preNum, preSum, cnt, pow10 arrays



//! The Solution below gave Time Limit Exceeded error for large test cases, so I had to optimize it using prefix sums and prefix products.
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();

        vector<int> ans(q, 0);
        const long long MOD = 1e9 + 7;

        for(int k = 0; k < q; k++){
            int start = queries[k][0];
            int end = queries[k][1];

            long long sum = 0;
            long long num = 0;

            for(int i = start; i <= end; i++){
                int digit = s[i] - '0';

                if(digit > 0){
                    sum += digit;
                    num = (num * 10 + digit) % MOD;
                }
            }

            if(num == 0){
                continue;
            }

            long long temp = 1LL * num * sum;
            int t = temp % MOD;

            ans[k] = t;
        }

        return ans;
    }
};