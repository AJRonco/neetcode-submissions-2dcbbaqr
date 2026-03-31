class LRUCache {

    struct listNode {
        int key;
        int value;
        listNode* next;
        listNode* previous;

        listNode() : key(0), value(0), next(nullptr), previous(nullptr) {}
        listNode(int x, int y) : key(x), value(y), next(nullptr), previous(nullptr) {}
        

    };
    

    listNode* head;
    listNode* tail;

private:
    std::unordered_map<int, listNode*> lruCache;
    int cacheCapacity;

public:
    LRUCache(int capacity) {

        cacheCapacity = capacity;
        head = new listNode(0,0);
        tail = new listNode(0,0);
        head->next = tail;
        tail->previous = head;

    }

    void removeNode(listNode* node) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    void addToEnd(listNode* node) {
        node->previous = tail->previous;
        node->next = tail;
        tail->previous->next = node;
        tail->previous = node;
    }

    int get(int key) {

        if (lruCache.count(key) == 0) {
            return -1;
        }
       
        listNode* node = lruCache[key];
        removeNode(node);
        addToEnd(node);
        
        return node->value;
        
    }

    void put(int key, int value) {
        // if cache is at or over capacity

        if (lruCache.count(key) != 0) {
            listNode* node = lruCache[key];
            node->value = value;
            removeNode(node);
            addToEnd(node);
            return;
        }

        if (lruCache.size() >= cacheCapacity) {
            listNode* temp = head->next;
            removeNode(temp);
            lruCache.erase(temp->key);
            delete temp;
        }
       
        listNode* newTail = new listNode(key, value);
        lruCache[key] = newTail;
        addToEnd(newTail);
                
            
              
        }
        
    
};
