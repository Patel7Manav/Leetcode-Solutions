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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=1;
        ListNode*curr=list1;
        while(i<a)
        {
            i++;
            curr=curr->next;
        }
        ListNode*temp1=curr;
        while(a<=b)
        {
            curr=curr->next;
            a++;
        }
        ListNode*temp2=curr->next;
        ListNode*temp3=list2;
        while(temp3->next!=NULL)
        {
            temp3=temp3->next;
        }
        temp1->next=list2;
        temp3->next=temp2;
        return list1;
    }
};