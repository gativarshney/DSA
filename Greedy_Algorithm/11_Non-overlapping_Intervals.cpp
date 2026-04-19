//! using greedy algorithm
//! sort the intervals based on their end time and then iterate through the intervals and count the number of non-overlapping intervals. The number of intervals to remove will be the total number of intervals minus the count of non-overlapping intervals.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int nonOverlap = 1;
        int lastEndTime = intervals[0][1];
        for(int i=1; i<n; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s >= lastEndTime){
                nonOverlap++;
                lastEndTime = e;
            }
        }
        return n - nonOverlap;
    }
};
// Time Complexity: O(nlogn) due to sorting the intervals based on their end times.
// Space Complexity: O(1) if we don't consider the space used for sorting, otherwise O(n) for the sorting algorithm.