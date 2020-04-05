/*
 * @Author: your name
 * @Date: 2020-04-05 07:44:03
 * @LastEditTime: 2020-04-05 08:20:32
 * @LastEditors: Please set LastEditors
 * @Description: 该文件实现了最不优先缓冲数据结构，支持get和put,时间复杂度都是O(1)
 * @FilePath: /leetcodeSolution/include/LFU.h
 */

//* 采用的方法是哈希表和平衡二叉树，在c++中set的底层实现是红黑树，用来模拟平衡二叉树
# ifndef _LFU_H
# define _LFU_H
# include <unordered_map>
# include <set>


struct Node{
    
    int cnt;        // 用来存储该key的使用次数
    int time;       // 用来存储该key最近一次使用的时间
    int key, value; // 保存key和value

    Node(int _cnt,int _time, int _key, int _value):cnt(_cnt),time(_time),key(_key),value(_value){}

    // 实现一个Node类的比较函数，在使用次数大的情况下，选大的那个
    // 如果使用次数相同，就比较最近的使用时间
    bool operator< (const Node& rhs) const{
        return cnt == rhs.cnt? time < rhs.time : cnt < rhs.cnt;
    }

};

class LFUCache{
    // 缓冲容量，时间戳
    int capacity, time;
    std::unordered_map<int, Node> key_table;
    std::set<Node> S;

public:
    LFUCache(int _capacity){
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key){
        if(capacity == 0) return -1;
        auto it = key_table.find(key);
        if(it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧的缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新的缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }

    void put(int key, int value){
        if(capacity==0) return;
        auto it = key_table.find(key);
        if(it == key_table.end()){
            if(key_table.size() == capacity){
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time,key,value);
            // 将新的缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key,cache));
            S.insert(cache);
        }else {
            Node cache = it ->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }

};


#endif

