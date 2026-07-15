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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        // return solve(l1,l2,0);
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int c = 0;
        while(a || b || c != 0){
            int x = a ? a->val : 0;
            int y = b ? b->val : 0;

            int sum = x + y + c;
            int val = sum % 10;
            c = sum / 10;

            curr -> next = new ListNode(val);

            curr = curr -> next;
            a = a ? a->next : NULL;
            b = b ? b->next : NULL;
        }
        return dummy -> next;
    }
};
