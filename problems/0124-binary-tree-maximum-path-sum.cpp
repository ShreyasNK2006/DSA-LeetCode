/*
 * Problem 0124: Binary Tree Maximum Path Sum
 * URL     : https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Solved  : 2026-04-27
 * Runtime : 0 ms
 * Memory  : 27.8 MB
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
    int dfs(TreeNode* node,int & maxsum)
    {
        if(!node)
        return 0;
        int leftsum=0,rightsum=0;
        if(node->left)
        leftsum=max(0,dfs(node->left,maxsum));
        if(node->right)
        rightsum=max(0,dfs(node->right,maxsum));
        int sum=node->val+leftsum+rightsum;
        maxsum=max(maxsum,sum);
        return node->val+max(leftsum,rightsum);

    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
};