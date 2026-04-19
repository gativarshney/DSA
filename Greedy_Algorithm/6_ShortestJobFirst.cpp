class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        long long sum = 0;
        long long waiting = 0;
        for(int i = 0; i < n; i++){
            sum += waiting;
            waiting += bt[i];
        }
        long long ans = sum / n;
        return ans;
    }
};
// Time Complexity: O(n log n) due to sorting the burst times.
// Space Complexity: O(1) as we are using only a constant amount of extra space