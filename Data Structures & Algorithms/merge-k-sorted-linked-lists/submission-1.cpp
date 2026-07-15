/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& nums) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i] -> val;
            pq.push({x,nums[i]});
        }
        ListNode* ans = new ListNode(0);
        ListNode* curr =  ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ListNode* node = it.second;
            curr->next = node;
            if(node->next){
                pq.push({node->next->val,node->next});
            }
            curr = curr->next;
        }
        return ans->next;
    }
};
