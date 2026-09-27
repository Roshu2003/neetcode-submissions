class Solution {
public:
    vector<int> arr;
    vector<vector<int>> ans;
    void solve(int i,vector<int> path){
        ans.push_back((path));
        for(int j = i; j < arr.size(); j++){
            if(j > i && arr[j] == arr[j - 1])continue;
            path.push_back(arr[j]);
            solve(j + 1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        arr = nums;
        sort(arr.begin(),arr.end());
        solve(0,{});
        return ans;
    }
};
