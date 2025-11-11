# Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k==1)
        return head;
        ListNode* temp =head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int countrev=0;
        temp=head;
        ListNode* newhead;
        ListNode* prev =nullptr;
        ListNode * top;
        ListNode * prevhead=nullptr;
        while(countrev<len/k)
        {
            int count=0;
            ListNode *front;
            prev=nullptr;
            top=temp;
            while(count<k)
            {
                count++;
                front = temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            if(countrev==0)
            newhead =prev;
            countrev++;
            if(prevhead)
            prevhead->next =prev;
            top->next=temp;
            prevhead=top;

        }
        return newhead;
    }
};