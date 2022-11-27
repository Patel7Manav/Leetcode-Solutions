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
    ListNode* removeNodes(ListNode* head) {
        vector<int>arr;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            arr.push_back(curr->val);
            curr=curr->next;
        }
        int si=arr.size();
        int mx=arr[si-1];
        for(int i=si-2;i>=0;i--)
        {
            if(arr[i]<mx)
                arr[i]=-1;
            else
                mx=arr[i];
        }
        ListNode *nhead=new ListNode();
        ListNode*cur=nhead;
        for(int i=0;i<si;i++)
        {
            if(arr[i]!=-1)
            {
                cur->next=new ListNode(arr[i]);
                cur=cur->next;
            }
        }
        return nhead->next;
    }
};