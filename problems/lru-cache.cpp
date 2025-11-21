/*
 * Problem: LRU Cache
 * Solved on: 2025-11-01
 * Runtime: 80 ms
 * Memory: 172.9 MB
*/

class LRUCache {
public:
    class node{
        public:
        int key,val;
        node *next;
        node *prev;
        node(int k,int v){
            key = k;
            val = v;
        }
    };
    int cap;
    unordered_map<int,node *> mp;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void updatecache(node *temp)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        node* first = head->next;
        temp->next = first;
        temp->prev= head;
        head->next = temp;
        first->prev = temp;
    }
    int get(int key) {
        auto it = mp.find(key);
        if(it==mp.end())
        return -1;
        else
        {
            int val =it->second->val;
            updatecache(it->second);
            return val;
        }
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it!=mp.end())
        {
            it->second->val = value;
            updatecache(it->second);
        }
        else
        {
            node *newnode = new node(key,value);
            if(mp.size()==cap)
            {
                mp.erase(tail->prev->key);
                node *temp2 = tail->prev->prev;
                temp2->next= tail;
                tail->prev=temp2;
            }
            node* first = head->next;
            newnode->next = first;
            newnode->prev = head;
            head->next= newnode;
            first->prev = newnode;;
            mp[key]=newnode;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */