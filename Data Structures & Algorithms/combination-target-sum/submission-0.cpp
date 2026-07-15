class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int n;
    void solve(int i, int sum,vector<int> &ds){
        if(sum == 0){
            ans.push_back(ds);
            return;
        }
        if(i >= n){
            if(sum == 0)ans.push_back(ds);
            return;
        }
        if(sum - v[i] >= 0){
            ds.push_back(v[i]);
            solve(i,sum - v[i],ds);
            ds.pop_back();
        }
        solve(i + 1,sum,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        v = nums;
        n = v.size();
        vector<int> ds;
        solve(0,target,ds);
        return ans;
    }
};
