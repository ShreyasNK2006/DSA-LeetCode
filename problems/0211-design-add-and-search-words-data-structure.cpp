/*
 * Problem 0211: Design Add and Search Words Data Structure
 * URL     : https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * Solved  : 2026-04-22
 * Runtime : 566 ms
 * Memory  : 615.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

struct Node{
    Node *linked[26]={nullptr};
    bool flag=false;
    void put(char ch,Node *node)
    {
        linked[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return linked[ch-'a'];
    }
    bool isend()
    {
        return flag;
    }
    void makeend()
    {
        flag=true;
    }
};
class WordDictionary {
private:
Node *root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *node=root;
        for(char c:word)
        {
            if(node->linked[c-'a']==nullptr)
            {
                node->put(c,new Node());
            }
            node=node->get(c);
        }
        node->makeend();
    }
    bool findword(string word,Node* node,int i)
    {
        if(i==word.size())
        return node->isend();
        if(!node)
        return false;
        if(word[i]!='.' && node->linked[word[i]-'a']!=nullptr)
            {
                if(findword(word,node->get(word[i]),i+1))
                return true;
            }
        if(word[i]=='.')
        {
            for(int c=0;c<26;c++)
            {
                if(node->linked[c])
                {
                    if(findword(word,node->get(c+'a'),i+1))
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return findword(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */