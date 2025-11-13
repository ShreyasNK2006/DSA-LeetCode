# LFU Cache
Solved on 2025-11-08

struct Node{
    int key;
    int val;
    int cnt;
    Node * next;
    Node * prev;
    Node(int k,int v)
    {
        key =k;
        val =v;
        cnt =1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head =new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addnode(Node * newNode)
    {
        Node* temp = head->next;
        newNode->next= temp;
        newNode->prev=head;
        temp->prev=newNode;
        head->next =newNode;
        size++;
    }
    void removenode(Node * newNode)
    {
        Node* back = newNode->prev;
        Node* front = newNode->next;
        back->next=front;
        front->prev=back;
        size--;
    }
};

class LFUCache {
private:
map<int,Node*> ll;
map<int,List*>freqlist;
int cap,minfreq,currsize;
public:
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
        currsize=0;
    }
    void updatelist(Node *node)
    {
        freqlist[node->cnt]->removenode(node);
        if(node->cnt== minfreq && freqlist[node->cnt]->size==0)
        minfreq++;
        List *newlist = new List();
        if(freqlist.find(node->cnt+1)!=freqlist.end())
        {
            newlist = freqlist[node->cnt+1];
        }
        node->cnt++;
        newlist->addnode(node);
        freqlist[node->cnt]=newlist;
    }
    int get(int key) {
        if(ll.find(key)!=ll.end())
        {
            int val = ll[key]->val;
            updatelist(ll[key]);
            return val;
        }
        else 
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0)
        return;
        if(ll.find(key)!=ll.end())
        {
            ll[key]->val=value;
            updatelist(ll[key]);   
        }
        else 
        {
            if(currsize==cap)
            {
                List *list = freqlist[minfreq];
                Node *temp= list->tail->prev;
                ll.erase(temp->key);
                freqlist[minfreq]->removenode(temp);
                delete(temp);
                currsize--;
            }
            currsize++;
            minfreq=1;
            List *temp1 ;
            if(freqlist.find(minfreq)!=freqlist.end())
            {
                temp1 = freqlist[minfreq];
            }
            else
            {
                temp1 = new List();
            }
            Node *newNode = new Node(key,value);
            temp1->addnode(newNode);
            ll[key]=newNode;
            freqlist[minfreq]=temp1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */