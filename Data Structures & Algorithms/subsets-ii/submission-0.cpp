class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int n;
    void solve(int i,vector<int> &ds){
        if(i >= n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(v[i]);
        solve(i + 1,ds);
        ds.pop_back();
        while(i + 1 < n && v[i] == v[i + 1])i++;
        solve(i + 1,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        v = nums;
        n = v.size();  
        sort(begin(v),end(v)); 
        vector<int> ds;
        solve(0,ds);
        return ans;
    }
};
