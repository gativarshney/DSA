class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(ch == '(') st.push({ch, i});
            else if(ch == ')'){
                if(!st.empty() && st.top().first == '(') st.pop();
                else st.push({ch, i});
            }
        }

        while(!st.empty()){
            int idx = st.top().second;
            st.pop();
            s.erase(idx, 1);
        }

        return s;
    }
};