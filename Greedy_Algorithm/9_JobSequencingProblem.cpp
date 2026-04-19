//! Greedy Approach to solve Job Sequencing Problem
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<int> ans(2);
        vector<int> track(n+1, -1);
        int cnt = 0, maxProfit = 0;
        vector<pair<int, int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        for(int i=0; i<n; i++){
            int deadlines = jobs[i].first;
            for(int j = deadlines; j > 0; j--){
                if(track[j] == -1){
                    track[j] = i;
                    maxProfit += jobs[i].second;
                    cnt++;
                    break;
                }
            }
        }
        ans[0] = cnt;
        ans[1] = maxProfit;
        return ans;
    }
};
// Time Complexity: O(nlogn) + O(n * maxDeadline) where n is the number of jobs and maxDeadline is the maximum deadline among the jobs.
// Space Complexity: O(n) for the track vector and the jobs vector.
//* It will give Time Limit Exceeded for large inputs due to the nested loop. To optimize, we can use a Disjoint Set Union (DSU) or Union-Find data structure to efficiently find the next available slot for scheduling jobs.

//! Optimized Greedy Approach using Disjoint Set Union (DSU)
class Solution {
  public:
    vector<int> parent;
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        int maxDeadline = -1;
        for(int i=0; i<n; i++){
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        sort(jobs.rbegin(), jobs.rend());
        parent.resize(maxDeadline + 1);
        for(int i=0; i<=maxDeadline; i++){
            parent[i] = i;
        }
        int cnt = 0;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            int p = jobs[i].first;
            int d = jobs[i].second;
            int availableSlot = find(d);
            if(availableSlot > 0){
                maxProfit += p;
                cnt++;
                parent[availableSlot] = find(availableSlot-1);
            }
        }
        return {cnt, maxProfit};
    }
};

// * 👉 DSU is not grouping elements here
// * 👉 It is acting like a "jump pointer system"
//! We use DSU to efficiently track the latest available time slot. Once a slot is occupied, we union it with its previous slot so future queries automatically skip filled slots
//? DSU is not just for components — it’s for skipping states efficiently