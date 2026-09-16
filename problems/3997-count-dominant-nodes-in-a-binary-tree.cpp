/*
 * Problem 3997: Count Dominant Nodes in a Binary Tree
 * URL     : https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/
 * Solved  : 2026-08-22
 * Runtime : 18 ms
 * Memory  : 338.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int permute(TreeNode* root,int &count)
    {
        int maxn =root->val;
        if(root->left)
        maxn =max(maxn,permute(root->left,count));
        if(root->right)
        maxn =max(maxn,permute(root->right,count));
        if(!root->left && !root->right)
        {
            count++;
            return max(maxn,root->val); 
        }
        if(maxn == root->val)
        count++;
        return maxn;
    }
    int countDominantNodes(TreeNode* root) {
        int count=0;
        int maxn=0;
        if(root)
        {
            maxn= max(root->val,permute(root,count));
        }
        return count;
    }
};