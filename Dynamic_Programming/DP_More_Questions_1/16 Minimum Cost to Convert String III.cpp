class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        int r = rules.size();
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, INF);

        dp[n] = 0;

        for(int i = n-1; i >= 0; i--){
            if(source[i] == target[i]){
                dp[i] = dp[i+1];
            }

            for(int k = 0; k < r; k++){
                string pat = rules[k][0];
                string rep = rules[k][1];

                int len = pat.size();
                if(i + len > n) continue;

                bool ok = true;
                int wild = 0;

                for(int j = 0; j < len; j++){
                    if(pat[j] == '*'){
                        wild++;
                    }
                    else if(pat[j] != source[i + j]){
                        ok = false;
                        break;
                    }

                    if(rep[j] != target[i + j]){
                        ok = false;
                        break;
                    }
                }

                if(!ok) continue;
                if(dp[i + len] == INF) continue;

                dp[i] = min(dp[i], dp[i + len] + 1LL * costs[k] + wild);
            }
        }

        return dp[0] == INF ? -1 : (int)(dp[0] % MOD);
    }
};