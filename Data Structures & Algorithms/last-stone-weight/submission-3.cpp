class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto it : nums){
            pq.push(it);
        }
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a == b)continue;
            pq.push(abs(a - b));
        }
        return (pq.size() == 0 ? 0 : pq.top());
    }
};
