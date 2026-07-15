class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        // vector<int> ans(n,1);
        // for(int i = 0)
        stack<int> st;
        vector<int> l(n,-1),r(n,n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();
            if(!st.empty())l[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty())r[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int d = (r[i] - l[i] - 1);
            cout<<d<<endl;
            ans = max(ans,nums[i] * d);
        }
        return ans;
    }
};
