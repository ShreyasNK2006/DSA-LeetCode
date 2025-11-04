# Palindrome Linked List
Solved on 2025-09-26

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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr)
        return false;
        if(head->next==nullptr)
        return true;
        ListNode* prev = new ListNode(head->val);
        ListNode* currentold =head->next;
        ListNode* rev = new ListNode(currentold->val,prev);
        while(currentold->next)
        {
            ListNode *temp = new ListNode(currentold->next->val,rev);
            rev=temp;
            currentold=currentold->next;
        }
        currentold =head;
        while(rev!=nullptr)
        {
            if(rev->val!=currentold->val)
            return false;
            rev=rev->next;
            currentold=currentold->next;
        }
        return true;
    }
};