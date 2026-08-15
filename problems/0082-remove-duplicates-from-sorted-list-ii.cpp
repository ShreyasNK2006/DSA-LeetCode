/*
 * Problem 0082: Remove Duplicates from Sorted List II
 * URL     : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Solved  : 2026-08-06
 * Runtime : 0 ms
 * Memory  : 15.7 MB
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = new ListNode();
        ListNode *shift = root;
        if(head==NULL)
        return NULL;
        else
        {
            int prev = head->val;
            head=head->next;
            int f=1;
            while(head)
            {
                if(head->val==prev)
                {
                    head=head->next;
                    f++;
                }
                else
                {
                    if(f==1)
                    {
                        ListNode* newnode = new ListNode(prev);
                        shift->next = newnode;
                        shift=newnode;
                    }
                    f=1;
                    prev=head->val;
                    head=head->next;
                }
            }
            if(f==1)
            {
                ListNode* newnode = new ListNode(prev);
                shift->next = newnode;
                shift=newnode;
            }
        }
        return root->next;
    }
};