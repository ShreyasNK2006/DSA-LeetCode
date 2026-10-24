/*
 * Problem 0337: House Robber III
 * URL     : https://leetcode.com/problems/house-robber-iii/
 * Solved  : 2026-10-01
 * Runtime : 0 ms
 * Memory  : 22.5 MB
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
    int maxc = 0;
    pair<int,int> traverse(TreeNode* node)
    {
        if(node==NULL)
        return {0,0};
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        pair<int,int> ls = traverse(l);
        pair<int,int> rs = traverse(r);
        int cs = max(ls.first,ls.second)+max(rs.second,rs.first);
        int ns = ls.second+rs.second+node->val;
        return {ns,cs};
    }
    int rob(TreeNode* root) {
        pair<int,int> t = traverse(root);
        maxc = max(t.first,t.second);
        return maxc;

    }
};