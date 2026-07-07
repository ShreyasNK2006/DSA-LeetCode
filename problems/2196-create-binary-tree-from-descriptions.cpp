/*
 * Problem 2196: Create Binary Tree From Descriptions
 * URL     : https://leetcode.com/problems/create-binary-tree-from-descriptions/
 * Solved  : 2026-06-07
 * Runtime : 146 ms
 * Memory  : 266.7 MB
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<TreeNode*> st;
        int n=descriptions.size();
        TreeNode* root;
        for(int i=0;i<n;i++)
        {
            TreeNode *newnode;
            if(mp.find(descriptions[i][0])!=mp.end())
            {
                if(mp.find(descriptions[i][1])==mp.end())
                {
                    newnode=new TreeNode();
                    newnode->val=descriptions[i][1];
                    mp[descriptions[i][1]]=newnode;
                }
                else
                {
                    newnode=mp[descriptions[i][1]];
                    st.erase(newnode);
                }
                if(descriptions[i][2]==1)
                mp[descriptions[i][0]]->left=newnode;
                else
                mp[descriptions[i][0]]->right=newnode;             
            }
            else
            {
                newnode=new TreeNode();
                newnode->val=descriptions[i][0];
                st.insert(newnode);
                TreeNode* node2;
                if(mp.find(descriptions[i][1])==mp.end())
                {
                    node2=new TreeNode();
                    node2->val=descriptions[i][1];
                    mp[descriptions[i][1]]=node2;
                }
                else
                {
                    node2=mp[descriptions[i][1]];
                    st.erase(node2);
                }
                mp[descriptions[i][0]]=newnode;                
                if(descriptions[i][2]==1)
                newnode->left=node2;
                else
                newnode->right=node2;
            }
        }
        for(auto s:st)
        root=s;
        return root;
    }
};