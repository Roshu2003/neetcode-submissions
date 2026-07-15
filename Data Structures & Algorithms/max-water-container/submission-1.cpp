class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int i = 0;
        int j = heights.size() - 1;
        while(i < j){
            int w = (j - i);
            int h = min(heights[i],heights[j]);
            ans = max(ans,h * w);
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
