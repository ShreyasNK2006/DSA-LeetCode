/*
 * Problem 3043: Find the Length of the Longest Common Prefix
 * URL     : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
 * Solved  : 2026-05-21
 * Runtime : 116 ms
 * Memory  : 168.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

struct Node
{
    Node * links[10]={nullptr};
    bool flag=false;
    bool containskey(int n)
    {
        return links[n]!=nullptr;
    }
    void put(int n,Node *node)
    {
        links[n]=node;
    }
    Node* get(int n)
    {
        return links[n];
    }
    void setend()
    {
        flag=true;
    }
};
typedef struct Node Node;
class Solution {
private:
Node *root;
public:
Solution(){
    root=new Node();
}
void insert(Node *node,int n)
{
    if(!node->containskey(n))
    {
        node->put(n,new Node());
    }
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(),n2=arr2.size();
        for(int i=0;i<n1;i++)
        {
            int d1=log10(arr1[i]);
            int p=pow(10,d1);
            Node* node=root;
            while(d1>=0)
            {
                int x=arr1[i]/p;
                insert(node,x);
                node=node->get(x);
                arr1[i]=arr1[i]-x*p;
                p/=10;
                d1--;
            }
            node->setend();
        }
        int maxlen=0;
        for(int i=0;i<n2;i++)
        {
            int d1=log10(arr2[i]);
            int p=pow(10,d1);
            int len=0;
            Node* node=root;
            while(d1>=0)
            {
                int x=arr2[i]/p;
                if(!node->containskey(x))
                break;
                else 
                len++;
                node=node->get(x);
                arr2[i]=arr2[i]-x*p;
                p/=10;
                d1--;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};