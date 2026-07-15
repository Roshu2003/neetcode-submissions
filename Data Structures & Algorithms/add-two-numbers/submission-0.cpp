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
    ListNode* solve(ListNode* a,ListNode* b,int c){
        if(!a && !b && c == 0)return NULL;
        int x = 0,y = 0;
        if(a)x = a->val;
        if(b)y = b -> val;
        int sum = x + y + c;
        int nodeval = sum % 10;
        int nc = sum / 10;

        ListNode* nxt = solve(a ? a->next : nullptr,b?b->next:NULL,nc);

        return new ListNode(nodeval,nxt);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1,l2,0);
    }
};
