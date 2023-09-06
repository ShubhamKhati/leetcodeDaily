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
    int sizeOfLL(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        if(head==NULL){
            for(int i=0; i<k; i++){
                ans.push_back(NULL);
            }
            return ans;
        }
        int length=sizeOfLL(head);
        int nums=length/k;
        int rem=length%k;
        vector<int>v(k,0);
        for(int i=0; i<k; i++){
             if(i<rem){
                 v[i]+=1;
             }
             v[i]+=nums;
        }
        ListNode* temp=head;
       for(int i=0; i<v.size(); i++){
           ans.push_back(temp);
           int cn=v[i]-1;
           if(temp==NULL)continue;
           while(cn--){
               temp=temp->next;
           }
           if(temp==NULL)continue;
           ListNode* nextnode=temp->next;
           temp->next=NULL;
           temp=nextnode; 
       }
       return ans;
    }
};