//! Brute Force (Time Limit Exceeded)

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        vector<int> howMany(n-1, 0);
        
        for(int i = 0; i < K; i++){
            double maxSection = -1;
            int maxIdx = -1;
            
            for(int j = 0; j < n-1; j++){
                double diff = stations[j+1] - stations[j];
                double num = howMany[j] + 1;
                double sectionLen = diff / num;
                
                if(maxSection < sectionLen){
                    maxSection = sectionLen;
                    maxIdx = j;
                }
            }
            
            howMany[maxIdx]++;
        }
        
        double ans = -1;
        for(int i = 0; i < n-1; i++){
            double diff = stations[i+1] - stations[i];
            double num = howMany[i] + 1;
            double sectionLen = diff / num;
            
            ans = max(ans, sectionLen);
        }
        
        return ans;
    }
};
//* Time Complexity: O(K * N) + O(N) ~ O(K * N) --> Quadratic Time Complexity
//* Space Complexity: O(N)


//! Optimized Approach (Priority Queue - Heap)


double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<double, int>> pq;
    
    for(int i = 0; i < n-1; i++){
        double gap = arr[i+1] - arr[i];
        pq.push({gap, i});
    }
    
    for(int i = 0; i < k; i++){
        auto top = pq.top();
        pq.pop();
        
        int maxSectionIdx = top.second;
        howMany[maxSectionIdx]++;
        
        double originalSectionLen = arr[maxSectionIdx + 1] - arr[maxSectionIdx];
        
        double newSectionLen = originalSectionLen / (double)(howMany[maxSectionIdx] + 1);
        
        pq.push({newSectionLen, maxSectionIdx});
    }
    
    double ans = pq.top().first;
    
    return ans;
}
//* Time Complexity: O(NlogN) + O(klogN)
//* SC: O(N-1)


//! Optimal Solution (Binary Search)

#include<bits/stdc++.h>
using namespace std;

int noOfGasStationsRequired(double dist, vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n-1; i++) {
        int numberInBetween = (arr[i + 1] - arr[i]) / dist;

        if ((arr[i+1] - arr[i]) == (numberInBetween * dist)) {
            numberInBetween--;
        }

        cnt += numberInBetween;
    }

    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    double maxGap = 0;
    
    for(int i = 0; i < n-1; i++){
        double gap = arr[i+1] - arr[i];
        maxGap = max(maxGap, gap);
    }

    double low = 0;
    double high = maxGap;
    const double diff = 1e-6;

    while(high - low > diff){
        double mid = low + (high - low) / 2.0;

        if(noOfGasStationsRequired(mid, arr) > k) low = mid;
        else{
            high = mid;
        }
    }

    return high;    
}

//* TC: O(N log(range))
//* SC: O(1)

// Binary Search on Answer
// Search Space:
// low = 0
// high = maximum gap between consecutive gas stations
//
// For every mid (maximum allowed distance):
// -> Calculate the number of new gas stations required.
// -> If required > k, mid is too small, so increase the distance (low = mid).
// -> Otherwise, mid is feasible, so try to minimize it further (high = mid).
//
// Helper Function:
// numberInBetween = gap / dist
// If gap is exactly divisible by dist, decrement by 1 because
// n equal segments require only (n - 1) new gas stations.
//
// Time Complexity: O(n * log(maxGap / 1e-6))
// Space Complexity: O(1)