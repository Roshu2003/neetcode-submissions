class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;
        int l = 0;
        int r = 0;
       
        for (int r = 0; r < n; r++) {

            while (!dq.empty() && nums[r] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(r);

            while (!dq.empty() && dq.front() < l)
                dq.pop_front();

            if (r - l + 1 == k) {
                ans.push_back(nums[dq.front()]);
                l++;
            }
        }

        return ans;
    }
};
