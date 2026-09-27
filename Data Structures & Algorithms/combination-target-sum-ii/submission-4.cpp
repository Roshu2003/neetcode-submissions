class Solution {
public:
    vector<vector<int>> ans;
    int k;
    vector<int> nums;
    void solve(int idx,vector<int> path,int curr){
        if(curr == k){
            ans.push_back(path);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1])continue;
            if(curr + nums[i] > k)break;
            
            path.push_back(nums[i]);
            solve(i + 1,path,curr + nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums = candidates;
        k = target;
        sort(nums.begin(),nums.end());
        solve(0,{},0);
        return ans;
    }
};
