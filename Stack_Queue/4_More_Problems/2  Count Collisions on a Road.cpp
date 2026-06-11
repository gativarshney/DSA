class Solution {
public:
    int countCollisions(string directions) {
        int col = 0;
        stack<char> st;
        for(int i=0; i<directions.size(); i++){
            char curr = directions[i];
            if(!st.empty()){
                char top = st.top();
                if(top == 'R' && curr == 'L'){
                    col += 2;
                    st.pop(); 
                    while(!st.empty() && st.top() == 'R'){
                        col += 1;
                        st.pop();
                    }
                    st.push('S');
                }
                else if(top == 'S' && curr == 'L'){
                    col += 1;
                    st.push('S');
                }
                else if(top == 'R' && curr == 'S'){
                    col += 1;
                    st.pop();
                    while(!st.empty() && st.top() == 'R'){
                        col += 1;
                        st.pop();
                    }
                    st.push('S');
                }
                else st.push(curr);
            }
            else st.push(curr);
        }
        return col;
    }
};
//? TC: O(N) SC: O(N)

//! Optimised Solution
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;
        while (i < n && directions[i] == 'L') {
            i++;
        }
        while (j >= 0 && directions[j] == 'R') {
            j--;
        }
        int collisions = 0;
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') {
                collisions++;
            }
        }
        return collisions;
    }
};
//? TC: O(N) SC: O(1)
// The optimized solution works by first skipping all the 'L' cars at the beginning of the string and all the 'R' cars at the end of the string, as they will never collide. Then, it counts the number of cars that are not 'S' (stationary) in the remaining substring, which represents the number of collisions that will occur. As each of these cars will eventually collide and become stationary, we can simply count them to get the total number of collisions.