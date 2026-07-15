class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        set<int> st(nums.begin(),nums.end());
        for(auto it:st){
            if(st.find(it - 1) == st.end()){
                int len = 1;
                while(st.find(it + len) != st.end())len++;

                ans = max(ans,len);
            }
        }
        return ans;
    }
};
