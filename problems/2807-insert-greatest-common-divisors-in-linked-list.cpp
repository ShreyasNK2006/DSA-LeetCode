/*
 * Problem 2807: Insert Greatest Common Divisors in Linked List
 * URL     : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
 * Solved  : 2026-06-17
 * Runtime : 5 ms
 * Memory  : 36 MB
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
    int gcd(int a,int b)
    {
        if(b==0)
        return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head)
        return head;
        ListNode *it1=head,*it2=head->next;
        while(it2)
        {
            ListNode *newnode= new ListNode(gcd(it1->val,it2->val));
            it1->next=newnode;
            newnode->next=it2;
            it1=it2;
            it2=it2->next;
        }
        return head;
    }
};