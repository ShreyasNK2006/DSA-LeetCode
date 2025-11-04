# Linked List Cycle II
Solved on 2025-09-26

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> freq;
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr)
        {
            if(freq.find(temp)!=freq.end())
            {
                return temp;
            }
            freq[temp]=count;
            count++;
            temp=temp->next;
        }
        return nullptr;
    }
};