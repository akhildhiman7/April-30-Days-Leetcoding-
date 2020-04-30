/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
public:
    queue<pair<int,pair<int,int>>> que;//(key,value,id)
    map<int,int> keyToValue, keyToId;
    int sz, maxSz, id;

    LRUCache(int capacity) {
        sz=id=0;
        maxSz=capacity;
    }

    int get(int key) {
        id++;
        map<int,int>::iterator it;
        it=keyToValue.find(key);
        if (it==keyToValue.end())
            return -1;
        que.push(make_pair(it->first,make_pair(it->second,id)));
        keyToId[it->first]=id;
        return it->second;
    }

    void put(int key, int value) {
        id++;
        if (keyToValue.find(key)==keyToValue.end())
            sz++;
        que.push(make_pair(key,make_pair(value,id)));
        keyToValue[key]=value;
        keyToId[key]=id;
        while (sz>maxSz){
            pair<int,pair<int,int>> tmp=que.front();
            que.pop();
            if (keyToId[tmp.first]==tmp.second.second){
                sz--;
                keyToValue.erase(tmp.first);
                keyToId.erase(tmp.first);
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
