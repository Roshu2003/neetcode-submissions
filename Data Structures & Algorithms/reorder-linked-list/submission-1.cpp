class Solution {
public:

    ListNode* find(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;

        }

        return slow;
    }


    ListNode* findR(ListNode* head){

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }


    void reorderList(ListNode* head) {

        if(!head || !head->next)
            return;


        // Find middle
        ListNode* mid = find(head);


        // Reverse second half
        ListNode* b = findR(mid->next);


        // Break list
        mid->next = NULL;


        // Merge
        ListNode* a = head;

        while(b){

            ListNode* an = a->next;
            ListNode* bn = b->next;


            a->next = b;
            b->next = an;


            a = an;
            b = bn;
        }
    }
};