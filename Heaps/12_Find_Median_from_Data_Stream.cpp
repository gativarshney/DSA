class MedianFinder {
public:
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
    
    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};

// Time Complexity: addNum -> O(log N), findMedian -> O(1)
// Space Complexity: O(n)
