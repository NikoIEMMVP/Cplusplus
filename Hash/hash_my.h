# pragma once
#include <iostream>


using namespace std;




template <class K, class V, class KeyOfValue>
struct __HIterator;



// 声明分割线 *********



template <class V>
struct HashNode{
    HashNode<V>* _next;
    V _data;

    HashNode(V data)
    :_next(nullptr), _data(data)
    {}
};





template<class K, class V, class KeyOfValue>
class HashTable{
public: 
    typedef HashNode<V> Node;
    typedef HashNode<V>* pNode;

    typedef __HIterator<K,V,KeyOfValue> iterator;

    // 迭代器中需要访问哈希表中的私有成员
    // 泛型友元声明

    template <class K, class V, class KeyOfValue>
    friend struct __HIterator;


    HashTable(size_t N){
        _table.resize(N);
        _size = 0;
    }

    


    bool Insert(const V& data){
        CheckCapacity();
        KeyOfValue kov;
        size_t index = kov(data) % _table.size();
        pNode cur = _table[index];
        while(cur){
            if(cur->_data == data){
                return false;
            }

            cur = cur->_next;
        }
        cur = new Node(data);
        cur->next = _table[index];
        _table[index] = cur;
        ++_size;
        return true;
    }

    void CheckCapacity(){
        if(_size == _table.size()){
            size_t newC = (_table.size() == 0 ? 10 : 2 * _table.size() );

            vector<pNode> newTable(newC);
            
            for(size_t i = 0; i < _table.size(); ++i){
                pNode cur = _table[i];
                KeyOfValue kov;
                while(cur){
                    size_t index = kov(cur->_data) % newTable.size();
                    pNode next = cur->_next;
                    cur->_next = newTable[index];
                    newTable[index] = cur;
                    cur = next;
                }

                _table[i] = nullptr;
            }

            _table.swap(newTable);
        }
    }
private: 
    vector<pNode> _table;
    size_t _size = 0;
    
};


template <class K, class V, class KeyOfValue>
struct __HIterator{
    typedef HashNode<V> Node;
    typedef HashNode<V*> pNode;

    typedef __HIterator<K, V, KeyOfValue> Self;
    typedef HashTable<K, V, KeyOfValue> HashT;

    pNode _node;
    HashT* _ht;

    __HIterator(const pNode node, const HashT* ht)
    :_node(node) , _ht(ht)
    {}

    V& operator*(){
        return _node->_data;
    }

    V* operator->(){
        return &operator*();
    }

    bool operator!=(const Self& it){
        return _node != it._node;
    }

    Self& operator++(){
        if(_node->_next){
            _node = _node->_next;
        }else{
            // 如果下一个节点为空，就要获取当前迭代器节点在表中的 index
            KeyOfValue kov;
            size_t index = kov(_node->_data) % _ht->_table.size();
            ++index;
            for(; index < _ht->_table.size(); ++index){
                if(_ht->_table[index]){
                    _node = _ht->_table[index];
                    break;
                }
            }

            if(index == _ht->_table.size()){
                _node = nullptr;
            }
        }

        return *this;
    }

    Self& operator++(int){
        Self temp = *this;
        if(_node->_next){
            _node = _node->_next;
        }else {
            KeyOfValue kov;
            size_t index = kov(_node->_data) % _ht->_table.size();
            ++index;
            for(; index < _ht->_table.size(); ++index){
                if(_ht->_table[index]){
                    _node = _ht->_table[index];
                    break;
                }
            }

            if(index == _ht->_table.size()){
                _node = nullptr;
            }
        }

        return temp;
    }
};