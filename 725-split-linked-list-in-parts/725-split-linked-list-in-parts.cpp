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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *>ans;
        ListNode *curr=head,*prev=head;
        int n=0;
        while(curr!=NULL)
        {
            curr=curr->next;
            n++;
        }
        curr=head;
        int times=n/k;
        int rem=n%k;
        int l;
        while(curr!=NULL)
        {
            if(rem>0)
            { l=times+1;
            rem--;}
            else
                l=times;
            int i=0;
            while(i<l-1)
            {
                curr=curr->next;
                i++;
            }
            ans.push_back(prev);
            ListNode *temp=curr;
            prev=curr->next;
            curr=curr->next;
            temp->next=NULL;
            k--;
        }
        if(k>0)
        {
            while(k--)
                ans.push_back(NULL);
        }
        return ans;
    }
};