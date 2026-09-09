class Node {
public:
    int key, val, freq;
    Node *next, *prev;
    Node(int k, int v)
        : key(k), val(v), freq(1), next(nullptr), prev(nullptr) {}
};
class LFUCache {
public:
    int cap;
    unordered_map<int, Node*> mp1; // key
    unordered_map<int, Node*> freqTail;
    map<int, Node*> mpf; // freq
    int min_freq = 1;
    LFUCache(int capacity) { this->cap = capacity; }

    int get(int key) {
        if (mp1.find(key) == mp1.end())
            return -1;
        auto node = mp1[key];
        node->freq++;
        auto previ = node->prev;
        auto nexti = node->next;
        previ->next = nexti;
        nexti->prev = previ;
        if (mpf.find(node->freq) != mpf.end()) {
            auto n1 = mpf[node->freq];
            auto p1 = n1->prev;
            n1->prev = node;
            p1->next = node;
            node->prev = p1;
            node->next = n1;
        } else {
            Node* taili = new Node(-1, -1);
            Node* headi = new Node(-1, -1);
            headi->prev = taili;
            taili->next = headi;
            mpf[node->freq] = headi;
            freqTail[node->freq] = taili;
            auto n1 = mpf[node->freq];
            auto p1 = n1->prev;
            n1->prev = node;
            p1->next = node;
            node->prev = p1;
            node->next = n1;
        }
        if (mpf[node->freq - 1]->prev == freqTail[node->freq - 1]) {
            if (min_freq == node->freq - 1)
                min_freq = node->freq;
        }
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (mp1.find(key) != mp1.end()) {
            mp1[key]->val = value;
            get(key);
            return;
        }
        if (mp1.size() == cap) {
            auto tail = freqTail[min_freq];
            auto node = tail->next;
            tail->next = node->next;
            node->next->prev = tail;
            mp1.erase(node->key);
            delete node;
        }
        if (mp1.find(key) == mp1.end()) {
            if (mpf.find(1) == mpf.end()) {
                Node* taili = new Node(-1, -1);
                Node* headi = new Node(-1, -1);
                headi->prev = taili;
                taili->next = headi;
                mpf[1] = headi;
                freqTail[1] = taili;
            }
            min_freq = 1;
            Node* node = new Node(key, value);
            node->freq = 1;
            auto n1 = mpf[node->freq];
            auto p1 = n1->prev;
            n1->prev = node;
            p1->next = node;
            node->prev = p1;
            node->next = n1;
            mp1[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */