class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        for(auto it : nums){
            int idx = abs(it) - 1;
            if(nums[idx] < 0)return abs(it);
            nums[idx] *= -1;
        }
        return -1;
    }
};
