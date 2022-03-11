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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode *curr=head,*last;
        int n=0;
        while(curr!=NULL)
        {
            if(curr->next==NULL)
                last=curr;
            curr=curr->next;
            n++;
        }
        if(k%n==0)
            return head;
        int t=k%n;
        t=n-t;
        curr=head;
        while(t>1)
        {
           curr=curr->next;
            t--;
        }
        ListNode *temp=curr->next;
       curr->next=NULL;
        last->next=head;
        return temp;
    }
};