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
    ListNode* swapNodes(ListNode* head, int k) {
        int c=0,n=0,one=0,second=0;
        ListNode *curr=head,*first;
        while(curr!=NULL)
        {   
            if(c==k-1)
            {    one=curr->val;
                first=curr;
            } 
            curr=curr->next;
            c++;
            n++;
        }
        curr=head;
         c=0;
        while(c!=(n-k))
        {
            curr=curr->next;
            c++;
        }
        second=curr->val;
        first->val=second;
        curr->val=one;
        return  head;
    }
};