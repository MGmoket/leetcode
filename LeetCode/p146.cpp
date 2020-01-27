/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

#include <map>
#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

namespace p146 {
    class LRUCache {
        map<int, int> mps;
        deque<int> lru;
        int m_capacity;
    public:
        LRUCache(int capacity) {
            m_capacity = capacity;
        }

        int get(int key) {
            if (mps.count(key) == 0) return -1;
            return mps[key];
        }

        void put(int key, int value) {
            auto finder = find(lru.begin(), lru.end(), key);
            if (finder != lru.end()) {
                mps.erase(*finder);
                lru.erase(finder);
            } else if (lru.size() == m_capacity) {
                mps.erase(lru.front());
                lru.pop_front();
            }
            lru.push_back(key);
            mps[key] = value;
        }
    };

	class LRUCache2 { // 更便于调整
		struct Node {
			Node* next;
			Node* pre;
			int key;
			int val;
			Node(int k, int n) :key(k), val(n), next(nullptr), pre(nullptr) {}
		};
		Node* head;
		Node* tail;
		unordered_map<int, Node*> HashMap;
		int size;
		int cap;
	public:
		LRUCache2(int capacity) :size(0), cap(capacity), head(nullptr), tail(nullptr) {
		}

		int get(int key) {
			Node* cur = HashMap[key];
			if (cur) {
				if (cap == 1 || cur == head) { return cur->val; }
				if (cur == tail) { tail = tail->pre; tail->next = nullptr; cur->next = head; cur->pre = nullptr; head->pre = cur; head = cur; return cur->val; }
				cur->pre->next = cur->next;
				cur->next->pre = cur->pre;
				cur->pre = nullptr;
				cur->next = head;
				head->pre = cur;
				head = cur;
				return cur->val;
			}
			return -1;
		}

		void put(int key, int value) {
			if (!cap)return;
			Node* cur = HashMap[key];
			if (cur) { cur->val = value; get(key); return; }
			if (size >= cap) {
				if (head == tail) {
					HashMap.erase(head->key);
					delete head;
					head = nullptr;
					tail = nullptr;
				}
				else {
					Node* tmp = tail;
					tail->pre->next = nullptr;
					tail = tail->pre;
					HashMap.erase(tmp->key);
					delete tmp;
				}
				size--;
			}
			if (head == nullptr) {
				head = new Node(key, value);
				tail = head;
				HashMap[key] = head;
			}
			else {
				Node* tmp = new Node(key, value);
				HashMap[key] = tmp;
				tmp->next = head;
				head->pre = tmp;
				head = tmp;
			}
			size++;
		}
	};
}

