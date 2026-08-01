//? Brute Force : TC: O(N * N), SC: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruit = 0;
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                st.insert(fruits[j]);
                if(st.size() <= 2){
                    maxFruit = max(maxFruit, j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxFruit;
    }
};

//? Better Approach ; TC: O(2 * N), SC: O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxFruits = 0;
        unordered_map<int, int> mpp;
        while(r < n){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            if(mpp.size() <= 2){
                maxFruits = max(maxFruits, r -  l + 1);
            }
            r++;
            
        }
        return maxFruits;
    }
};

//? Optimal Approach; TC: O(N), SC: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxFruits = 0;
        unordered_map<int, int> mpp;
        while(r < n){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size() <= 2){
                maxFruits = max(maxFruits, r -  l + 1);
            }
            r++;
        }
        return maxFruits;
    }
};