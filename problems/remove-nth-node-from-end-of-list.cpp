# Remove Nth Node From End of List
Solved on 2025-11-07

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
        if(head==nullptr || head->next==nullptr)
        return nullptr;
     int count=0;
     ListNode* temp = head;
     while(temp)
     {
        count++;
        temp=temp->next;
     }   
     count-=n;
     n=0;
     temp=head;
     ListNode* prev;
     while(n<count)
     {
        prev=temp;
        temp=temp->next;
        n++;
     }
     if(temp->next!=nullptr)
     {
        temp->val=temp->next->val;
        temp->next=temp->next->next;}
    else
    {
        prev->next=nullptr;
    }
     return head;
    }
};