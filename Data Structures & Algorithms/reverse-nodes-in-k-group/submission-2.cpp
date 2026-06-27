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
    ListNode* getKthNode(ListNode* curr, int k){
        while(curr!=nullptr && k>0){
            curr = curr->next;
            k--;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while(true){
            ListNode* kth = getKthNode(groupPrev, k);

            if(kth == nullptr) break;

            ListNode* nextGroup = kth->next;
            ListNode* groupStart = groupPrev->next;

            //Reverse the nodes

            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while(curr != nextGroup){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            groupPrev->next = kth;
            groupPrev = groupStart;
        
        }

        return dummy.next;
    }
};
