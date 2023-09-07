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
  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* temp=head;
       vector<int>v;
       while(temp!=NULL){
           v.push_back(temp->val);
           temp=temp->next;
       }
       reverse(v.begin()+left-1,v.begin()+right);
       temp=head;
       int i=0;
       while(temp!=NULL){
           temp->val=v[i++];
           temp=temp->next;
       }
       return head;
        
    }
};