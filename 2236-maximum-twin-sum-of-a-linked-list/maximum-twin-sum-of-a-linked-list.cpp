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
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp=nullptr;
        int res=0;
        while(fast && fast->next){
            fast=fast->next->next;
            ListNode* nxt=slow;
            slow=slow->next;
            nxt->next=temp;
            temp=nxt;
        }
        while(temp && slow){
            res=max(res,temp->val+slow->val);
            temp=temp->next;
            slow=slow->next;
        }
        return res;
    }
};