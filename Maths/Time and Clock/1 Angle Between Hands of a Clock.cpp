class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 1 min of minute movement --> hour will cover = 0.5 degree
        // 1 min of minute movement --> minute will cover = 6 degree

        double h = (hour % 12) * 30 + minutes * 0.5;

        double m = minutes * 6;

        double ans = min(abs(h - m), 360 - abs(h - m));

        return ans;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)


// 1 min of minute movement --> hour will cover = 0.5 degree
// As, 1 hour (60 minutes) leads to 30 degree movement of hour hand (360/12 = 30), so 1 min will lead to 30/60 = 0.5 degree movement of hour hand


// 1 min of minute movement --> minute will cover = 6 degree
// As, 360 degree movement of minute hand leads to 60 min, so 1 min will lead to 360/60 = 6 degree movement of minute hand