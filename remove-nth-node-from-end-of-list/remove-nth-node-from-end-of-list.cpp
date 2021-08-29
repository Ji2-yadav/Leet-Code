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
        ListNode* temp = head;
        int cnt = 1;
        while(cnt!=n+1)
        {
            temp = temp->next;
            cnt++;
        }
        if(temp==NULL)
        {
            return head->next;
        }
        ListNode* temp2 = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        ListNode* temp3 = temp2;
        temp3 = temp3->next->next;
        
        temp2->next = temp3;
        
        return head;
        
    }
};