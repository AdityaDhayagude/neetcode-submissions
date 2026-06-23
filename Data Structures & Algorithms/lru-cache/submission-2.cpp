class LRUCache {
public:
    struct Node{
        int key; 
        int val;
        Node* prev; 
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){} //initializer list way
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0); 
        head->next = tail;
        tail->prev = head;
 }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->val = value;
            remove(mp[key]);
            insert(mp[key]);

            return;
        }

        mp[key] = new Node(key, value);
        insert(mp[key]);

        if(mp.size()> cap){
            Node* del = tail->prev;
            remove(tail->prev);
            mp.erase(del->key);
            delete(del);
        }
    }
};
