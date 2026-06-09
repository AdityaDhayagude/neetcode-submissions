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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNodes = 0;
        if(head == nullptr ) return nullptr;
        ListNode *p = head; 

        while(p!=nullptr){
            p = p->next;
            totalNodes++;
        }

        if(n>totalNodes) return nullptr;
        
        int count = 0;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* tail = &dummy;  // tail starts at dummy   
        p = head; 

        while(count< totalNodes - n){
            tail = p;
            p = p->next;
            count++;
        }

        tail->next = p->next;
        p->next = NULL;
        delete(p);

        return dummy.next;

        
        
    }
};
