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
    int count=0;
    ListNode *h1;
    Solution(ListNode* head) {
        ListNode*curr=head;
        h1=head;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
    }
    
    int getRandom() {
        int pick=(rand()%count);
        ListNode *curr=h1;
        while(pick--)
        {
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */