class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr;
        int cnt = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) cnt++;
            else arr.push_back(nums[i]);
        }

        for(int i = 0; i < cnt; i++){
            arr.push_back(0);
        }

        nums = arr;
    }
};

// Better
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = 0;

        while(j < n && nums[j] != 0){
            j++;
        }

        int i = j + 1;

        while(i < n && j < n){
            while(i < n && nums[i] == 0){
                i++;
            }

            if(i < n){
                swap(nums[i], nums[j]);
            }

            while(j < n && nums[j] != 0){
                j++;
            }
        }
    }
};

// Best
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};