/*
 * Problem 0208: Implement Trie (Prefix Tree)
 * URL     : https://leetcode.com/problems/implement-trie-prefix-tree/
 * Solved  : 2026-04-08
 * Runtime : 22 ms
 * Memory  : 50.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

struct Node
{
    Node* links[26]={nullptr};
    bool flag=false;
    bool containskey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    Node * get(char ch)
    {
        return links[ch-'a'];
    }
    void setend()
    {
        flag =true;
    }
    bool checkend()
    {
        return flag;
    }
};
typedef struct Node Node;
class Trie {
    private:
    Node *root;
public:
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!(node->containskey(word[i])))
            node->put(word[i],new Node());
            node = node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
            return false;
            node =node->get(word[i]);
        }
        return node->checkend();
    }
    
    bool startsWith(string prefix) {
        Node* node= root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containskey(prefix[i]))
            return false;
            node =node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */