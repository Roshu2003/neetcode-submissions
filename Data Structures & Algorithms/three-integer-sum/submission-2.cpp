class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            int sum = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int t = nums[l] + nums[r];
                if(t == sum){
                    vector<int> temp = {nums[i],nums[l],nums[r]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    l++;
                    r--;
                                    }
                else if(t > sum)r--;
                else l++;
            }
        }
        for(auto it : st)ans.push_back(it);
        return ans;
    }
};
