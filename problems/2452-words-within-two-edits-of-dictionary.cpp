/*
 * Problem 2452: Words Within Two Edits of Dictionary
 * URL     : https://leetcode.com/problems/words-within-two-edits-of-dictionary/
 * Solved  : 2026-04-22
 * Runtime : 43 ms
 * Memory  : 51.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

struct Node
{
    Node* link[26]={nullptr};
    bool flag=false;
    bool expression(int n)
    {
        if(link[n]!=nullptr)
        return true;
        else
        return false;
    }
    bool isend()
    {
        return flag;
    }
    void makeend()
    {
        flag=true;
    }
    void put(int n,Node *node)
    {
        link[n]=node;
    }
    Node* get(int n)
    {
        return link[n];
    }
};
    class Solution {
        private:
        Node* root;
public:
    Solution(){
        root=new Node();
    }
    void insert(string &word)
    {
        Node *node=root;
        for(char c:word)
        {
            if(node->link[c-'a']==nullptr)
            {
                node->put(c-'a',new Node());
            }
            node=node->get(c-'a');
        }
        node->makeend();
    }
    bool searchdict(Node* node,string key,int cnt,int i)
    {
        if(cnt>2)
        return false;
        if(!node)
        return false;
        if(i==key.size())
        return node->isend();
        int ind=(int)key[i]-'a';
        if(node->expression(ind))
        {
            if(searchdict(node->link[ind],key,cnt,i+1))
            return true;
        }
        if(cnt<2)
        {
            bool cond=false;
            for(int k=0;k<26;k++)
            {
                if(k==ind)
                continue;
                if(node->link[k] && searchdict(node->link[k],key,cnt+1,i+1))
                return true;
            }
        }
        return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for(string q:dictionary)
        insert(q);
        vector<string> res;
        for(string q:queries)
        {
            bool cond= searchdict(root,q,0,0);
            if(cond)
            res.push_back(q); 
        }
        return res;
    }
};