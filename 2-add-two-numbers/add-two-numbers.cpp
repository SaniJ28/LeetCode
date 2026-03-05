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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* add=new ListNode(-1);
        ListNode* temp=add;
        while(temp1!=NULL || temp2!=NULL){
        int sum=carry;
        if(temp1){
            sum+=temp1->val;
            temp1=temp1->next;
        }
        if(temp2){
            sum+=temp2->val;
            temp2=temp2->next;
        }
        ListNode* node=new ListNode(sum%10);
        temp->next=node;
        temp=node;
        carry=sum/10;
        }
    if(carry){
         ListNode* Node= new ListNode(carry);
         temp->next=Node;
    }
    return add->next;
    }
};                                                        