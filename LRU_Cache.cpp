// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4




#include<cstdio>
#include<unordered_map>
#include<iostream>

using namespace std;
class LRUCache {
public:

    unordered_map<int,pair<int,int>> occ;
    int cap;
    int tracker =0;
    int size =0;
    unordered_map<int,pair<int,int>>::iterator it;
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        it = occ.begin();
        while(it != occ.end()){
            if(it->first == key){
                it->second.first = tracker +1;
                tracker++;
                return it->second.second;
            }else{
                it++;
            }
        }
        return -1;
    }

    void put(int key, int value) {

        if(size == cap){
            it = occ.begin();
            int lru = INT_MAX;
            int l_key;
            while(it != occ.end()){
                if(it->first == key ) {
                    pair<int,int>temp;
                    temp.first = tracker+1;
                    temp.second = value;
                    occ[key] = temp;
                    tracker++;
                    return;
                }
                if(it->second.first < lru){
                    lru = it->second.first;
                    l_key = it->first;
                }
                it++;
            }
            it = occ.find (l_key);
            occ.erase (it);
            pair<int,int> temp;
            temp.first = tracker +1;
            tracker++;
            temp.second = value;
            occ[key] = temp;

        }else{
            if(occ.find(key) != occ.end()) {
            pair<int,int>temp;
            temp.first = tracker+1;
            temp.second = value;
            occ[key] = temp;
            tracker++;
            return;
            }
            pair<int,int> temp;
            temp.first = tracker+1;
            temp.second = value;
            tracker++;
            occ[key] = temp;
            size++;
        }




    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
