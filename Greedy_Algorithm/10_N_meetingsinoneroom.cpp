class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> time;
        for(int i = 0; i < n; i++){
            time.push_back({start[i], end[i]});
        }
        sort(time.begin(), time.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        int freeTime = time[0].second;
        int maxMeet = 1;
        for(int i=1; i<n; i++){
            int s = time[i].first;
            int e = time[i].second;
            if(s > freeTime){
                maxMeet++;
                freeTime = e;
            }
        }
        return maxMeet;
    }
};
// Time Complexity: O(nlogn) due to sorting the meetings based on their end times.  
// Space Complexity: O(n) for the time vector that stores the start and end times of the meetings.

//* We sort the meetings based on their end times to ensure that we always consider the meeting that finishes earliest first. This allows us to maximize the number of meetings that can be scheduled in one room without overlap.

//? Gievn Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting. That's why start > freeTime and not start >= freeTime

//! If job index is also required in the output, we can modify the code as follows:
class Solution {
  public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        // {{start, end}, index}
        vector<pair<pair<int,int>, int>> time;

        for(int i = 0; i < n; i++){
            time.push_back({{start[i], end[i]}, i + 1}); // 1-based index
        }

        // sort by end time
        sort(time.begin(), time.end(), [](auto &a, auto &b){
            return a.first.second < b.first.second;
        });

        vector<int> selected;

        int freeTime = time[0].first.second;
        selected.push_back(time[0].second);

        for(int i = 1; i < n; i++){
            int s = time[i].first.first;
            int e = time[i].first.second;

            if(s > freeTime){
                selected.push_back(time[i].second);
                freeTime = e;
            }
        }

        return selected;
    }
};