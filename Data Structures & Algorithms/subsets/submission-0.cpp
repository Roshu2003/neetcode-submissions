class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int n;
    void dfs(int i,vector<int> &ds){
        if(i >= n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(v[i]);
        dfs(i + 1,ds);
        ds.pop_back();
        dfs(i + 1,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        v = nums;
        n = nums.size();
        vector<int> ds;
        dfs(0,ds);
        return ans;
    }
};
