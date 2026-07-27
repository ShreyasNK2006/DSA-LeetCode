/*
 * Problem 2130: Maximum Twin Sum of a Linked List
 * URL     : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 * Solved  : 2026-06-14
 * Runtime : 8 ms
 * Memory  : 138.4 MB
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
    int pairSum(ListNode* head) {
        vector<int> arr;
        int n=0;
        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
            n++;
        }
        int maxs=0;
        for(int i=0;i<n/2;i++)
        {
            maxs=max(maxs,arr[i]+arr[n-i-1]);
        }
        return maxs;
    }
};