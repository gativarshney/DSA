//! Leetcode Hard

class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int fr = freq[val];
        group[fr].push(val);
        maxFreq = max(maxFreq, fr);
    }
    
    int pop() {
        int value = group[maxFreq].top();
        group[maxFreq].pop();

        freq[value]--;

        if(group[maxFreq].empty()){
            maxFreq--;
        }

        return value;
    }
};

//* push(val): O(1)
//* pop(): O(1)
//* Space Complexity: O(n) where n is the total number of pushed elements not yet popped.