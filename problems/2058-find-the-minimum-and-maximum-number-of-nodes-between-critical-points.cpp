/*
 * Problem 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * URL     : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 * Solved  : 2026-08-31
 * Runtime : 12 ms
 * Memory  : 133.8 MB
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        int mind=INT_MAX,maxd=0;
        int curr=-1,pass=-1;
        int fst=-1;
        int n=temp.size();
        for(int i=1;i<n-1;i++)
        {
            bool valid = (temp[i]>temp[i+1] && temp[i]>temp[i-1])||(temp[i]<temp[i-1] && temp[i]<temp[i+1]);
            if(curr!=-1)
            pass=curr;
            curr=-1;
            if(fst==-1 && valid)
            fst=i;
            if(pass==-1 && valid)
            pass=i;
            else if(valid)
            curr=i;
            if(curr!=-1)
            {
                mind=min(mind,curr-pass);
                maxd=curr-fst;
            }
        }
        if(mind!=INT_MAX)
        return {mind,maxd};
        else
        return {-1,-1};
    }
};