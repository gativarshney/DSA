//! Brute Force Approach
class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);
        int span = 1;
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (prices[i] <= price) {
                span++;
            } else {
                break;
            }
        }
        return span;
    }
};
// TC: O(no. of days) SC: O(no. of next calls)

//! Optimized Approach 
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index = -1; 
    StockSpanner() {
        index = -1; 
        st = {};
    }
    int next(int price) {
        index = index + 1;
        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return ans;
    }
};
// TC: O(2 * N) , SC: O(N)
