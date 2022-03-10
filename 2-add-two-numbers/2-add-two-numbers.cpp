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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode((l1->val+l2->val)%10);
        int carry=(l1->val+l2->val)/10;
        ListNode *curr1=l1->next,*curr2=l2->next,*curr=head;
        while(curr1!=NULL && curr2!=NULL)
        {
            int sum=carry+curr1->val+curr2->val;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            carry=sum/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(curr1==NULL)
        {
            while(curr2!=NULL)
            {
                int sum=carry+curr2->val;
            curr->next=new ListNode(sum%10);
                curr=curr->next;
            carry=sum/10;
                curr2=curr2->next;
            }
        }
        else if(curr2==NULL)
        {
             while(curr1!=NULL)
            {
                int sum=carry+curr1->val;
            curr->next=new ListNode(sum%10);
                 curr=curr->next;
            carry=sum/10;
                 curr1=curr1->next;
            }
        }
        if(carry>0)
            curr->next=new ListNode(carry);
        return head;
    }
};