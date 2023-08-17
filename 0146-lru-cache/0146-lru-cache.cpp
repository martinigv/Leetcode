class LRUCache {
public:
    struct ListNode {
        int val;
        int key;
        ListNode* pre;
        ListNode* next;
        ListNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
    };
    int max;
    unordered_map<int, ListNode*> mp;
    ListNode* head;
    ListNode* tail;

    void deleteNode(int key) {
        ListNode* toDelete = mp[key];
        toDelete->pre->next = toDelete->next;
        toDelete->next->pre = toDelete->pre;
        delete toDelete;
        mp.erase(key);
    }

    LRUCache(int capacity) {
        max = capacity;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        ListNode* node = mp[key];
        node->pre->next = node->next;
        node->next->pre = node->pre;

        tail->pre->next = node;
        node->pre = tail->pre;
        node->next = tail;
        tail->pre = node;

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            get(key); // Update usage order
            return;
        }

        if (mp.size() >= max) {
            deleteNode(head->next->key);
        }

        ListNode* newNode = new ListNode(key, value);
        tail->pre->next = newNode;
        newNode->pre = tail->pre;
        newNode->next = tail;
        tail->pre = newNode;
        mp[key] = newNode;
    }
};