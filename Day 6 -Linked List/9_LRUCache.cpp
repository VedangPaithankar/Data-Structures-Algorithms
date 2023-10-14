/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

https://leetcode.com/problems/lru-cache/description/
*/

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // Move the accessed node to the front (most recently used)
            Node* node = cache[key];
            moveToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move it to the front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            // Key doesn't exist, add it to the cache
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);

            // Check if the capacity is exceeded, and evict the LRU node if necessary
            if (cache.size() > capacity) {
                Node* removed = removeFromTail();
                cache.erase(removed->key);
                delete removed;
            }
        }
    }

private:
    void moveToFront(Node* node) {
        // Remove the node from its current position
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // Move the node to the front
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void addToFront(Node* node) {
        // Add the node to the front
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    Node* removeFromTail() {
        // Remove the tail node (LRU node)
        Node* removed = tail->prev;
        tail->prev = removed->prev;
        removed->prev->next = tail;
        return removed;
    }
};