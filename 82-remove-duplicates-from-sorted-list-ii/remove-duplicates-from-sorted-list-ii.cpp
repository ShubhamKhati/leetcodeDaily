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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL )return head;
        map<int,int>m;
        ListNode* temp=head;
        while(temp!=NULL){
            m[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        ListNode* prev=head;
        ListNode* aft=prev->next;
        while(aft!=NULL){
           if(m[aft->val]>1){
               prev->next=aft->next;
               aft=aft->next;
           }
           else{
               prev=prev->next;
               aft=aft->next;
           }
        }
        if(m[head->val]>1){
            head=head->next;
        }
        return head;

    }
};