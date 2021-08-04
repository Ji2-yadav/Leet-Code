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
    vector<int> vec;  
   while(head!=NULL){
       vec.push_back(head->val);     // pushing back the element of linkedlist to vector
       head = head->next;
   }
    int n = vec.size();
    
    stack<int> s;
    vector<int> v;
    for(int i = n-1;i>=0;i--){
        if(s.empty()){            // Check if the size of stack is empty then simply push back 0 to the vector
            v.push_back(0);
        }
        else if(!s.empty()&& s.top()>vec[i]){     //if stack is not empty and the element at the top of the stack is greater than the current element(vec[i]) then push it back to the vector v. 
            v.push_back(s.top());
        }
        else if(!s.empty()&&s.top()<=vec[i]){    // if stack is not empty and the element at the top of the stack is less than the current element(vec[i]) then we pop the element from the stack until s.top() becomes greater than the current element or it becomes empty.
            while(!s.empty() && s.top() <= vec[i]){
                s.pop();
            }
            if(s.empty()){   // checking if the stack is empty then push back 0 else push back the s,top() to the vector .
                v.push_back(0);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(vec[i]);
    }
    reverse(v.begin(),v.end());       // reversing vector to get the desired output
    return v;
}
};