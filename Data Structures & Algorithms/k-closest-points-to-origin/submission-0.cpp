class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < nums.size(); i++){
            auto p = nums[i];
            int dis = p[0] * p[0] + p[1] * p[1];
            // if(pq.empty())
            pq.push({dis,i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(nums[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
