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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        for(ListNode*curr=head;curr!=NULL;curr=curr->next)
        {
            ListNode*temp=curr;
            int cv=temp->val;
            while(temp!=NULL)
            {
                temp=temp->next;
                if(temp!=NULL && temp->val>cv)
                {
                    ans.push_back(temp->val);
                    break;
                }
            }
            if(temp==NULL)
                ans.push_back(0);
        }
        return ans;
    }
};