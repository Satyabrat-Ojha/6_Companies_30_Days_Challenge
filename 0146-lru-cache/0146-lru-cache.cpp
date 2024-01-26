class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            Node* t = m[key];
            delete_node(t);
            add_node(t);
            return t->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* t = m[key];
            t->val = value;
            delete_node(t);
            add_node(t);
        }
        else {
            if(capacity == 0) {
                Node* x = head->next;
                m.erase(x->key);
                delete_node(x);
                capacity++;
            }
            Node* n = new Node(key,value);
            add_node(n);
            m[key] = n;
            capacity--;
        }
    }

    void add_node(Node* temp) {
        Node* t = tail->prev;
        t->next = temp;
        temp->prev = t;
        temp->next = tail;
        tail->prev = temp;
    }

    void delete_node(Node* temp) {
        Node* p = temp->prev;
        Node* n = temp->next;
        p->next = n;
        n->prev = p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */