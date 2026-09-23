class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = target - nums[i];
            if(mp.count(sum)){
                return {mp[sum],i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
