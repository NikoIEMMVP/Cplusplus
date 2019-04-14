#include <iostream>
#include <deque>

using namespace std;

template<class T, class Container = deque<T> >
class Queue
{
public:
    void Push(const T& x)
    {
        _con.push_back(x);
    }

    void Pop()
    {
        _con.pop_front();
    }

    T& Front()
    {
        return _con.front();
    }

    size_t Size()
    {
        return _con.size();
    }

    bool Empty()
    {
        return _con.empty();
    }

    T& Back()
    {
        return _con.back();
    }


private:
    Container _con;
};


int main()
{
    Queue<int> qqq;
    qqq.Push(444);
    qqq.Push(555);
    qqq.Push(666);
    qqq.Push(777);
    qqq.Push(888);

    while(!qqq.Empty())
    {
        cout << qqq.Front() << endl;
        qqq.Pop();
    }

    cout << endl;
    return 0;
}

