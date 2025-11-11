# Rotate List
Solved on 2025-09-28

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)
        return head;
        int count=0;
        ListNode* temp = head;
        ListNode* end;
        while(temp)
        {
            count++;
            end=temp;
            temp=temp->next;
        }
        if(k>=count)
        k%=count;
        if(k==0)
        return head;
        temp=head;
        end->next=head;
        count-=k;
        while(--count)
        {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};