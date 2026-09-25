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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        int c = 0;
        while(a || b || c != 0){
            int x = a ? a -> val : 0;
            int y = b ? b -> val : 0;
            int sum = x + y + c;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            c = sum / 10;
            if(a)
                a = a -> next;
            if(b)
                b = b -> next;
        }
        return ans -> next;
    }
};
