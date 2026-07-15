class Solution {
public:
    int dfs(int i,vector<int> & nums,bool flage){
        if(i == nums.size())return flage?0:-1e6;
        if(flage)return max(0,nums[i] + dfs(i + 1,nums,true));
        return max(dfs(i + 1,nums,false),nums[i] + dfs(i + 1,nums,true));
    }
    int maxSubArray(vector<int>& nums) {
        return dfs(0,nums,false);
    }
};
