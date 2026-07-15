class LRUCache {
public:
    struct Node{
        int key;
        int value;
        struct Node *prev;
        struct Node *next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    typedef struct Node Node;

    unordered_map<int, Node*> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void push_front(Node *curr) {
        Node *first = head->next;

        curr->prev = head;
        curr->next = first;

        first->prev = curr;
        head->next = curr;
    }

    void remove(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    void move_front(Node *curr) {
        remove(curr);
        push_front(curr);
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        else {
            move_front(mp[key]);
            return mp[key]->value;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // exist
            Node *curr = mp[key];
            curr->value = value;
            move_front(curr);
        }
        else {
            // not exist
            Node *curr = new Node(key, value);
            mp[key] = curr;
            push_front(curr);
            cap--;

            if (cap < 0) {
                Node *last = tail->prev;
                remove(last);
                mp.erase(last->key);
                delete last;
                cap++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */