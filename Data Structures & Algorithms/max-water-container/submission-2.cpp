class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l = 0;
        int n = heights.size();
        int r = n - 1;
        while(l < r){
            int len = r - l;
            ans = max(ans,len * min(heights[l],heights[r]));
            if(heights[l] < heights[r])l++;
            else r--;
        }
        return ans;
    }
};
