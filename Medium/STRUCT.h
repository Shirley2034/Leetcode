//
// Created by shirleyz on 2024/7/8.
//

#ifndef STRUCT_H
#define STRUCT_H
#include <map>
#include <unordered_map>
#include <vector>


class STRUCT {
public:
    class Node {
    public:
        int val;
        Node *next;
        Node *random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

    class Lc138 {
    public:
        class Solution {
            std::map<Node *, Node *> cachedNode;

        public:
            Node *copyRandomList(Node *head) {
                if (head == nullptr) {
                    return nullptr;
                }
                if (!cachedNode.count(head)) {
                    Node headNew(head->val);
                    cachedNode[head] = &headNew;
                    headNew.next = copyRandomList(head->next);
                    headNew.random = copyRandomList(head->random);
                }
                return cachedNode[head];
            }
        };
    };

    class Lc146 {
    public:
        struct DLinkedNode {
            int key, value;
            DLinkedNode *prev;
            DLinkedNode *next;

            DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {
            }

            DLinkedNode(int _key, int _val): key(_key), value(_val), prev(nullptr), next(nullptr) {
            }
        };

        class LRUCache {
        private:
            std::unordered_map<int, DLinkedNode *> cache;
            DLinkedNode *head;
            DLinkedNode *tail;
            int size;
            int capacity;

        public:
            LRUCache(int _capacity): capacity(_capacity), size(0) {
                head = new DLinkedNode();
                tail = new DLinkedNode();
                head->next = tail;
                tail->prev = head;
            }

            int get(int key) {
                if (!cache.count(key)) {
                    return -1;
                }
                DLinkedNode *node = cache[key];
                moveToHead(node);
                return node->value;
            }

            void put(int key, int value) {
                if (!cache.count(key)) {
                    auto *node = new DLinkedNode(key, value);
                    cache[key] = node;
                    addToHead(node);
                    size++;
                    if (size > capacity) {
                        removeTail();
                        size--;
                    }
                } else {
                    DLinkedNode *node = cache[key];
                    node->value = value;
                    moveToHead(node);
                }
            }

            void addToHead(DLinkedNode *node) {
                node->next = head->next;
                head->next->prev = node;
                head->next = node;
                node->prev = head;
            }

            void moveToHead(DLinkedNode *node) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                addToHead(node);
            }

            void removeTail() {
                DLinkedNode *node = tail->prev;
                cache.erase(node->key);
                node->prev->next = tail;
                tail->prev = node->prev;
                delete node;
            }
        };
    };

    class Lc200 {
    public:
        void dsp(std::vector<std::vector<char> > &grid, int i, int j) {
            grid[i][j] = '0';
            if (i > 0 && grid[i - 1][j] == '1') {
                dsp(grid, i - 1, j);
            }
            if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
                dsp(grid, i + 1, j);
            }
            if (j > 0 && grid[i][j - 1] == '1') {
                dsp(grid, i, j - 1);
            }
            if (j < grid[i].size() - 1 && grid[i][j + 1] == '1') {
                dsp(grid, i, j + 1);
            }
        }

        int numIslands(std::vector<std::vector<char> > &grid) {
            int num = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == '1') {
                        dsp(grid, i, j);
                        num++;
                    }
                }
            }
            return num;
        };
    };

    class Lc146_2 {
    public:
        class LRUCache {
            struct DLinkedNode {
                int key;
                int value;
                DLinkedNode *prev;
                DLinkedNode *next;

                DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {
                }

                DLinkedNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {
                }
            };

            int size;
            int capacity;
            std::map<int, DLinkedNode *> cacheMap;
            DLinkedNode *head;
            DLinkedNode *tail;

        public:
            LRUCache(int capacity): capacity(capacity), size(0) {
                head = new DLinkedNode();
                tail = new DLinkedNode();
                head->next = tail;
                tail->prev = head;
            }

            int get(int key) {
                auto it = cacheMap.find(key);
                if (it == cacheMap.end()) {
                    return -1;
                }
                //将当前节点加移动头节点
                moveToHead(it->second);
                return cacheMap[key]->value;
            }

            void put(int key, int value) {
                //首先判断key是否存在
                auto it = cacheMap.find(key);
                if (it == cacheMap.end()) {
                    //key不存在则添加到哈希表中
                    auto *node = new DLinkedNode(key, value);
                    cacheMap[key] = node;
                    addToHead(node);
                    size++;
                    if (size > capacity) {
                        //超出缓存，删除尾节点
                        removeTail();
                        size--;
                    }
                } else {
                    //更新节点值
                    cacheMap[key]->value = value;
                    //更新头节点
                    moveToHead(cacheMap[key]);
                }
            }

            void addToHead(DLinkedNode *node) {
                head->next->prev = node;
                node->next = head->next;
                head->next = node;
                node->prev = head;
            }

            void moveToHead(DLinkedNode *node) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                head->next->prev = node;
                node->next = head->next;
                node->prev = head;
                head->next = node;
            }

            void removeTail() {
                DLinkedNode *node = tail->prev;
                node->prev->next = tail;
                tail->prev = node->prev;
                cacheMap.erase(node->key);
                delete node;
            }
        };
    };
};


#endif //STRUCT_H
