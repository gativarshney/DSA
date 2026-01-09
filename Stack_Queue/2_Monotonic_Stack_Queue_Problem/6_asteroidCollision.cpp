class Solution {
private:
    bool isCancel(int a, int b){
        if(a >= 0 && b < 0) return true;
        return false;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        int i = 0;
        while(i < n){
            bool isPush = true;
            while(!st.empty() && isCancel(st.top(), asteroids[i])){
                if(abs(st.top()) < abs(asteroids[i])) st.pop();
                else if(abs(st.top()) == abs(asteroids[i])){
                    st.pop();
                    isPush = false;
                    break;
                }
                else{
                    isPush = false;
                    break;
                }
            }
            if(isPush) st.push(asteroids[i]);
            i++;
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//? TC: O(N) SC:O(N)