/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *dummy=new ListNode(0);
        ListNode * head=dummy;
        ListNode * temp=head;
        while(l1!=nullptr || l2!=nullptr || carry!=0){

            int a=(l1==nullptr)? 0 : l1->val;
            int b=(l2==nullptr)? 0 : l2->val;

            int ans=a+b+carry;
            
            temp ->next =new ListNode(ans%10);
            temp=temp->next;

            carry=ans/10;

            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        return head->next;

        
    }
};