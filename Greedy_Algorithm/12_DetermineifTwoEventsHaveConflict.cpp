class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
        int part1Start = stoi(event1[0].substr(0, 2)) * 60;
        part1Start += stoi(event1[0].substr(3, 2));

        int part1End = stoi(event1[1].substr(0, 2)) * 60;
        part1End += stoi(event1[1].substr(3, 2));

        int part2Start = stoi(event2[0].substr(0, 2)) * 60;
        part2Start += stoi(event2[0].substr(3, 2));

        int part2End = stoi(event2[1].substr(0, 2)) * 60;
        part2End += stoi(event2[1].substr(3, 2));

        if(part2Start >= part1Start && part2Start <= part1End) return true;
        if(part1Start >= part2Start && part1Start <= part2End) return true;
        return false;
    }
};
// Time Complexity: O(1) since we are just parsing the time strings and comparing them.
// Space Complexity: O(1) since we are using a constant amount of space to store the parsed time values.
//* We convert the time from "HH:MM" format to total minutes from the start of the day to make it easier to compare the start and end times of the events. Then we check if the start time of one event falls within the duration of the other event, which would indicate a conflict.