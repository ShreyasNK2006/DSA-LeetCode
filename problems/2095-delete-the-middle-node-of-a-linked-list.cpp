/*
 * Problem 2095: Delete the Middle Node of a Linked List
 * URL     : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 * Solved  : 2026-06-15
 * Runtime : 0 ms
 * Memory  : 312.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr | head->next==nullptr)
        return nullptr;
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};