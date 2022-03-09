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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev=NULL,*curr=head;
        if(head==NULL || head->next==NULL)
            return head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val==curr->next->val)
            {
                ListNode *temp=curr->next;
                while(temp->next!=NULL && temp->next->val==curr->val)
                    temp=temp->next;
                curr=temp->next;
                if(prev==NULL)
                    head=curr;
                else
                prev->next=temp->next;
            }
            else
            {
            prev=curr;    
            curr=curr->next;
            }
        }
        return head;
    }
};