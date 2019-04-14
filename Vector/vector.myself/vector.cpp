#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vector{
    typedef T* iterator;
    typedef const T* const_iterator;

public:
    Vector()
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endOfstorage(nullptr)
    {}
    
    Vector(size_t n, T v)
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endOfstorage(nullptr)
    {
        _start = new T[n];
        for(int i = 0; i < n; i++)
        {
            _start[i] = v;
        }
        _finish = _start + n;
        _endOfstorage = _start + n;

        // cout << n << endl;
        // cout << (void *)_start << endl;
        // cout << (void *)_finish << endl;
        // cout << (void *)_endOfstorage << endl;

        // cout << Size() << endl;
        // cout << Capacity() << endl;  
    }

    Vector(const Vector<T>& v)
    {
        //开辟空间
        _start = new T[v.Capacity()];
        //深拷贝，拷贝内容
        for(int i = 0; i < v.Size(); i++)
        {
            _start[i] = v[i];
        }
        //更新
        _finish = _start + v.Size();
        _endOfstorage = _start + v.Capacity();
    }

    ~Vector()
    {
        if(_start)
        {
            delete[] _start;
            _start = _finish = _endOfstorage = nullptr;
        }
    }


    T& operator=(const Vector<T> v)
    {
        Swap(v);
        return *this;
    }

    void Swap(Vector<T> v)
    {
        swap(_start, v._start);
        swap(_finish, v._finish);
        swap(_endOfstorage, v._endOfstorage);
    }


    size_t Size() const
    {
        return _finish - _start;
    }

    size_t Capacity() const
    {
        return _endOfstorage - _start;
    }

    void PushBack(const T& val)
    {
        if(Size() == Capacity())
        {
            size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
            Reserve(newC);
        }

        *_finish = val;
        ++_finish;
    }

    void Reserve(size_t n)
    {
        if(n > Capacity())
        {
            size_t sz = Size();
            //创建新空间
            T* tmp = new T[n];

            //判断原空间是否为空
            if(_start)
            {
                //拷贝内容
                //如果类型是string，那就是浅拷贝，会出现问题，因为存储的是指针，实际内容在另外一片空间
                //原因是对储存的指针所指向的内容的二次释放
                //深拷贝，调用T类型的赋值运算符重载完成拷贝
                //memcpy(tmp, _start, sizeof(T) * sz);
                
                for(int i = 0; i < sz; i++)
                {
                    tmp[i] = _start[i];
                }
                //释放原有空间
                delete[] _start;
            }
            _start = tmp;
            _finish = _start + sz;
            _endOfstorage = _start + n;
        }
    }

    void Resize(size_t n, const T& val = T())
    {
        if(n <= Size())
        {
            _finish = _start + n;
        }
        else
        {
            if(n > Capacity())
            {
                Reserve(n);
            }
            //Size() ~ n
            while(_finish != _start + n)
            {
                *_finish = val;
                ++_finish;
            }
        }
    }
    // void Reserve_my(size_t newC)
    // {
    //     if(newC > Capacity())
    //     {
    //         T* start = new T[newC];
    //         T* endOfstorage = start + sizeof(T) * newC;
    //         T* old_start = _start;
    //         T* new_start = start;
    //         T* new_finish = nullptr;
    //         int i = 0;

    //         while(i < Size())
    //         {
    //             *new_start = *old_start;
    //             new_start++;
    //             old_start++;
    //             i++;
    //         }

    //          new_finish = new_start;

    //          _start = start;
    //          _finish = new_finish;
    //          _endOfstorage = endOfstorage;
            

    //     }
    // }

    const T& operator[](size_t pos) const
    {
        assert(pos < Size());
        return _start[pos];
    }
    T& operator[](size_t pos)
    {
        assert(pos < Size());
        return _start[pos];
    }

    iterator begin()
    {
        return _start;
    }

    iterator end()
    {
        return _finish;
    }

    const_iterator begin() const
    {
        return  _start;
    }

    const_iterator end() const
    {
        return _finish;
    }

    //insert,erase 存在迭代器实效问题
    //insert :增容导致迭代器失效,增容之后更新迭代器

    void Insert(iterator pos, const T& val)
    {
        assert(pos >= _start && pos <= _finish);
        size_t len = pos - _start;
        if(_finish == _endOfstorage)
        {
            size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
            Reserve(newC);
        }
        //增容之后要更新迭代器的位置
        pos = _start + len;
        iterator end = _finish;
        while(end > pos)
        {
            *end = *(end - 1);
            end--;
        }

        *pos = val;
        _finish++;

    }

    //Erase 导致迭代器失效：可能导致迭代器访问越界，或者位置访问衣长
    //获取Erase的返回值，更新迭代器
    iterator Erase(iterator pos)
    {
        assert(pos >= _start && pos < _finish);
        iterator begin = pos + 1;
        while(begin < _finish)
        {
            *(begin - 1) = *begin;
            begin++;
        }
        --_finish;
        return pos;
    }


private:
    T* _start;
    T* _finish;
    T* _endOfstorage;
};


template <class T>
void PrintVector(const Vector<T>& v)
{
    for(int i = 0; i < v.Size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void testvector4()
{
    Vector<string> v2;
    v2.PushBack("hi");
    v2.PushBack("w");
    v2.PushBack("y");
    v2.PushBack("h");     
    v2.PushBack("!");
    PrintVector(v2);
    v2.Resize(4);
    PrintVector(v2);
    

}
void testvector()
{
    Vector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);
    v.Insert(v.begin() + 1,8);
    PrintVector(v);

    


}
int main()
{
    // Vector<string> v;
   // v.PushBack("1");
    // v.PushBack("2");
    // v.PushBack("3");
    //string s1("hhh");

    Vector<string> v1(4,"g");
    PrintVector(v1);
    cout << "v1.size()" << " " << v1.Size() << endl;

    Vector<string> v2(v1);
    PrintVector(v1);
    //Vector<int> i1(4,100);
    //PrintVector(i1);

    // cout << v1.Size() << endl;
    // cout << v1.Capacity() << endl;

    //testvector4();
    return 0;
}
