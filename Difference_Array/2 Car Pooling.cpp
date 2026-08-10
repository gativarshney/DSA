class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> d(1002, 0);

        int maxSize = 0;

        for(auto it : trips){
            int x = it[0];
            int s = it[1];
            int e = it[2];

            d[s] += x;
            d[e] -= x;

            maxSize = max(maxSize, e + 1);
        }
        
        vector<int> arr(maxSize, 0);

        arr[0] = d[0];

        if(arr[0] > capacity) return false;

        for(int i = 1; i < maxSize; i++){
            arr[i] = arr[i - 1] + d[i];

            if(arr[i] > capacity) return false;
        }

        return true;
    }
};

// d[e] -= x is used instead of d[e + 1] -= x because in this problem, the end index e is exclusive. This means that the passengers are dropped off at station e, and we do not need to account for them in the next station. Therefore, we decrement the difference array at index e to indicate that the passengers are no longer present after station e.