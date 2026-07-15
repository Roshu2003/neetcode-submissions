class Solution {
public:
    vector<vector<int>> ans;
    int n;
    vector<int> v;
    void solve(int i,vector<int> &ds){
        if(i == n){
            ans.push_back(v);
            return;
        }
        for(int j = i; j < n; j++){
            // ds.push_back(v[j]);
            swap(v[j],v[i]);
            solve(i + 1,ds);
            swap(v[i],v[j]);
            // ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        v = nums;
        n = v.size();
        vector<int> ds;
        solve(0,ds);
        return ans;
    }
};
