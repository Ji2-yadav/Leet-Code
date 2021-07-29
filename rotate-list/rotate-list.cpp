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
    void push(ListNode** head_ref, ListNode* tail)
    {
        tail->next = (*head_ref);
    }
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head)
        return NULL;
       if(k==0)
        return head;
       int cnt=1;
       ListNode* tail = head;
       while(tail->next!=NULL)
       {
           tail = tail->next;
           cnt++;
       }
        
       k %= cnt;
       if(k==0)
           return head;
       ListNode* curr=head;
       for(int i=0;i<cnt-k-1;i++)
           curr = curr->next;
       
       ListNode* newhead = curr;
       newhead = newhead->next;
       curr->next=NULL;
       
       push(&head,tail);
        
       return newhead;
               
    }
};