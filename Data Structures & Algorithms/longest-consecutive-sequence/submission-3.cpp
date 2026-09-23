class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(auto it : nums){
            if(!st.count(it - 1)){
                int len = 1;
                while(st.find(len + it) != st.end()){
                    len++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
