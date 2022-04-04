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
        ListNode *slow=head,*fast=head;
        int i=1;
        if(head->next==NULL)
        {
            delete head;
            return NULL;
        }
        while(i<n && fast!=NULL)
        {
            fast=fast->next;
            i++;
        }
        if(fast->next==NULL)
        {
            ListNode *tem=head->next;
            delete head;
            return tem;
        }
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            
            slow=slow->next;
            fast=fast->next;
        }
       
        ListNode *temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
        
    }
};