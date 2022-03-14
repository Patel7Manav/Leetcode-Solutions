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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head->next,*prev=NULL;
        while(curr!=NULL)
        {   int sum=0;
            while(curr->val!=0)
            {
                sum+=curr->val;
                curr=curr->next;
            }
            if(prev==NULL)
            {
                head->val=sum;
                prev=head;
            }
         else
         {
             prev->next->val=sum;
             prev=prev->next;
            
         }
         curr=curr->next;
        }
        prev->next=NULL;
        return head;
    }
};