#include <iostream>
#include <list>

using namespace std;
    
template<class T>
struct ListNode
{
    ListNode(const T& val = T())
    :_next(nullptr)
    ,_prev(nullptr)
    ,_data(val)
    {}

    ListNode<T>* _next;
    ListNode<T>* _prev;
    T _data;
};

template <class T>
struct ListIterator
{
    typedef ListNode<T>* pNode;
    typedef ListIterator<T> self;

    pNode _node;

    ListIterator(pNode node)
    :_node(node)
    {}

    self& operator++()
    {
        _node = _node->_next;
        return *this;
    }

    self& operator--()
    {
        _node = _node->_prev;
        return *this;
    }

    self operator++(int)
    {
        self tmp(*this);
        _node = _node->_next;
        return tmp;
    }

    self operator--(int)
    {
        self tmp(*this);
        _node = _node->_prev;
        return tmp;
    }

    //获取节点的data
    T& operator*()
    {
        return _node->_data;
    }

    T* operator->()
    {
        return &_node->_data;
    }

    //iterator != l.end()
    //比较两个迭代器封装的节点是否一样
    bool operator!=(const self& it)
    {
        return _node != it._node;
    }


};

template <class T>
struct ConstListIterator
{
    typedef ListNode<T>* pNode;
    typedef ConstListIterator<T> self;

    pNode _node;

    ConstListIterator(pNode node)
    :_node(node)
    {}

    self& operator++()
    {
        _node = _node->_next;
        return *this;
    }

    self& operator--()
    {
        _node = _node->_prev;
        return *this;
    }

    self operator++(int)
    {
        self tmp(*this);
        _node = _node->_next;
        return tmp;
    }

    self operator--(int)
    {
        self tmp(*this);
        _node = _node->_prev;
        return tmp;
    }

    //获取节点的data
    const T& operator*()
    {
        return _node->_data;
    }

    const T* operator->()
    {
        return &_node->_data;
    }

    //iterator != l.end()
    //比较两个迭代器封装的节点是否一样
    bool operator!=(const self& it)
    {
        return _node != it._node;
    }


};


template<class T>
class List
{
public:
    typedef ListNode<T> Node;
    typedef Node* pNode;
    typedef ListIterator<T> iterator;
    typedef ConstListIterator<T> const_iterator;
    
    //const对象不能调用非const成员函数，只能调用const成员函数
    //但是const成员函数operator++，operator--不能修改成员——node的值，
    //导致const迭代器无法执行++，--操作。
    //typedef const ListIterator<T> const_iterator;

    List(const T& val = T())
        :_head(new Node[1])
        {
            _head->_next = _head;
            _head->_prev = _head;
        }

    List(const List<T>& lst)
    {
        //创建头指针
        _head = new Node;
        _head->next = _head;
        _head->_prev = _head;
        //拷贝每一个节点,迭代器从头开始遍历每一个节点
        //插入到当前list对象中去
        for(const auto& e : lst)
        {
            PushBack(e);
        }
    }

    ~List()
    {
        Clear();
        if(_head)
        {
            delete _head;
            _head = nullptr;
        }
    }

    //传统写法
    // List<T>& operator=(const List<T>& lst)
    // {
    //     if(this != &lst)
    //     {
    //         //释放原有的节点
    //         Clear();
    //         for(const auto& e : lst)
    //         {
    //             PushBack(e);
    //         }
    //     }
    // }

    //现代写法
    List<T>& operator=(List<T> lst)
    {
        swap(_head,lst._head);
        return *this;
    }

    iterator begin()
    {
        return iterator(_head->_next);
    }

    iterator end()
    {
        return iterator(_head);
    }

    const_iterator begin() const
    {
        return const_iterator(_head->_next);
    }

    const_iterator end() const
    {
        return const_iterator(_head);
    }

    //Erase:迭代器失效
    //获取Erase的返回值(当前被删除的节点的下一个位置)，更新迭代器。
    iterator Erase(iterator pos)
    {
        if(pos != end())
        {
            pNode cur = pos._node;
            pNode prev = cur->_prev;
            pNode next = cur->_next;
            prev->_next = next;
            next->_prev = prev;
            delete cur;
            //更新迭代器
            pos = iterator(next);
        }
        return pos;
    }

     void PushBack(const T& val)
    {
        pNode curNode = new Node(val);
        pNode prev = _head->_prev;
        prev->_next = curNode;
        curNode->_prev = prev;
        curNode->_next = _head;
        _head->_prev = curNode;
    }


    void Insert(iterator pos, const T& val)
    {
        pNode new_node = new Node(val);
        pNode cur = pos._node;
        pNode prev = cur->_prev;
        prev->_next = new_node;
        new_node->next = cur;
        cur->_prev = new_node;
    }

    void PushFront(const T& val)
    {
        Insert(begin(),val);
    }

    void PopFront()
    {
        Erase(begin());
    }

    void PopBack()
    {
        Erase(--end());
    }

    void Clear()
    {
        if(_head)
        {
            pNode cur = _head->_next;
            while(cur != _head)
            {
                pNode next = cur->_next;
                delete cur;
                cur = next;
            }

            _head->_next = _head;
            _head->_prev = _head;
        }
    }



private:
    pNode _head;
};

// class Date
// {
// public:
//     int _year;
//     int _month;
//     int _day;

// };

template<class T>
void PrintList(const List<T>& lt)
{
    auto lit = lt.begin();
    while(lit != lt.end())
    {
        cout << *lit << " ";
        lit++;
    }
    cout << endl;
}

// void TestList2()
// {
//     List<Date> lst;
//     lst.PushBack(Date());
//     lst.PushBack(Date());
//     lst.PushBack(Date());

//     List<Date>::iterator lit = lst.begin();
//     while(lit != lst.end())
//     {
//         lit.operator->()->_year = 2018;
//         lit-> _year = 2018;
//         cout << lit->_year << "-" << lit->_month << "-" \
//         << lit->_day << "-";
//         lit++;
//     }
//     cout << endl;
// }

int main()
{
    // TestList2();
    return 0;
}


// int main()
// {
//     List<int> lst;
//     lst.PushBack(1);
//     lst.PushBack(2);
//     lst.PushBack(3);
//     lst.PushBack(4);

//     //*********
//     List<int>::iterator lit = lst.begin();
//     while(lit != lst.end())
//     {
//         cout << *lit;
//         lit++;
//     }    

//     cout << endl;
//     return 0;
// }