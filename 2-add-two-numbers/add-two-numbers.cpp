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
        ListNode* temp1=l1; ListNode* temp2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy; int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int num=temp1->val+temp2->val+carry;
            if(num>9){
                num=num%10;
                carry=1;
            }
            else{
                carry=0;
            }
            temp->next=new ListNode(num);
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int num=temp1->val+carry;
            if(num>9){
                num=num%10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* node=new ListNode(num);
            temp->next=node;
            temp=node;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int num=temp2->val+carry;
            if(num>9){
                num=num%10;
                carry=1;
            }
            else{
                carry=0;
            }
           ListNode* node=new ListNode(num);
            temp->next=node;
            temp=node;
            temp2=temp2->next;
        }
        if(carry!=0){
            ListNode* node= new ListNode(carry);
            temp->next=node;
            temp=node;
        }
        temp->next=NULL;
        return dummy->next;
    }
};