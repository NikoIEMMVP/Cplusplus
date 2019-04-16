#include <iostream>
using namespace std;

//**********类型模板参数**********//


template<class T>
T Add(const T& a, const T& b)
{
    return a + b ;
}

//非类型模板参数
template<class T ,size_t N>
class Array{

private:
    T _arr[N];
};

void Test1(){
    Array<int,10> a1;
    Array<double,100> a2;
    int a = 10;
    int b = 20;
    int c = Add(10,20);
    cout << c << endl;
    cout << typeid(c).name() << endl;
    return;
}


//**********函数模板特化**********//


template<class T>
bool isGreater(const T& a, const T& b){
    return a > b;
}

//模板特化要求：
//1.要有一个通用模板类型
//2.模板参数为空
//3.函数名后要有需要特化的类型，要与模板参数的形式一致
//4.一般不去写函数模板的特化，函数模板的特化比较复杂，有时候会报一些奇怪的错误

template<>
bool isGreater<char*&>(char*& a, char*& b){
    if(strcmp(a,b) > 0)
        return true;
    return false;
}


void Test2(){

    // int a = 10;
    // int b = 66;
    // cout << isGreater(b,a) << endl;

    char* s1= "hello";
    char* s2 = "world";
    cout << isGreater(s2,s1) << endl;

}

//**********类模板特化**********//

template<class T1, class T2>
class Date{
public:
    Date(){
        cout << "Date(T1,T2)" << endl;
    }
private:
    T1 _d1;
    T2 _d2;
};

// //类模板的全特化
template<>
class Date<int,char>{
public:
    Date(){
        cout << "Date(int,char)" << endl;
    }
private:
    int _d1;
    char _d2;
};

//类模板的半特化
//1.部分特化
template<class T>
class Date<T,char>{
public:
    Date(){
        cout << "Date(T,char)" << endl;
    }
private:
    char _d1;
    T _d2;
};

//2.对模板参数进一步进行限制
template<class T1, class T2>
class Date<T1*, T2*>{
public:
    Date(){
        cout << "Date(T1*,T2*)" << endl;
    }
private:
    T1* _d1;
    T2* _d2;
};

template<class T1, class T2>
class Date<T1&, T2&>{
public:
    Date(){
        cout << "Date(T1&,T2&)" << endl;
    }
private:
    T1* _d1;
    T2* _d2;
};

void Test3(){
    Date<int, int> d1; // T T
    Date<int,char> d2; // int char
    Date<double,char> d3; //T char
    Date<char*, char*> d4; // T* T*
    Date<int&, int&> d5; //T&  T&
}


//**********类型萃取**********

//通用版本的拷贝函数
//不适合一些需要深拷贝的自定义类型
template<class T>
void Copy(T* dst, const T* src, size_t sz){
    memcpy(dst, src, sizeof(T) * sz);
}

//赋值拷贝
//但如果是自定义类型的话 效率不高
template<class T>
void Copy(T* dst, T* src, size_t sz){
    for(size_t i = 0; i < sz; ++i){
        dst[i] = src[i];
    }
}

//这时候就需要另一种拷贝函数
//判断T的类型
//如果是内置类型，就用memcpy
//如果是自定义类型，就用赋值拷贝

//缺点：效率太低 时间复杂度O(n^2)
bool isPODType(const char* tp){
    static char* TypeArr[] = {"int","unsigned int", "short","unsigned short" ,"double", "float", \
    "long" ,"long double", ".."};
    for(int i = 0; i < sizeof(TypeArr) / sizeof(TypeArr[0]); i++){
        if(strcmp(tp,TypeArr[i])){
            return true;
        }

        return false;
    }
}

template<class T>
void Copy(T* dst, const T* src, size_t sz){
    if(isPODType(typeid(T).name())){
        memcpy(dst, src, sizeof(T) * sz);
    }
    else{
        for(size_t i = 0; i < sz; i++){
            dst[i] = src[i];
        }
    }
}

//*******************************

struct FlaseType{
    static bool Get(){
        return false;
    }
};

struct TrueType{
    static bool Get(){
        return true;
    }
};

template<class T>
struct TypeTraits{
    typedef FlaseType isPodType;
};

template<>
struct TypeTraits<int>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<char>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<short>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<double>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<long>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<float>{
    typedef TrueType isPodType;
};

//...........

template<class T>
void Copy(T* dst, const T* src, size_t sz){
    if(TypeTraits<T>::isPodType::Get()){
        cout << typeid(T).name() << ": memcpy" << endl;
        memcpy(dst, src, sizeof(T) * sz); 
    }
    else{
        cout << typeid(T).name() << ": operator=" << endl;
        for(int i = 0; i < sz; i++){
            dst[i] = src[i];
        }
    }
}

// int main()
// {
//     int arr1[] = {1,2,3,4,5,6,7};
//     int arr2[7];
//     Copy(arr2, arr1, 7);

//     string str1[] = {"123", "456","789"};
//     string str2[3];
//     Copy(str2, str1, 3);
//     return 0;
// }

//********** STL 类型萃取设计方法 **********//
struct TrueType{

};

struct FlaseType{

};

template<class T>
struct TypeTraits{
    typedef FlaseType isPodType;
};

template<>
struct TypeTraits<int>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<char>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<short>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<double>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<long>{
    typedef TrueType isPodType;
};

template<>
struct TypeTraits<float>{
    typedef TrueType isPodType;
};


//...........

template<class T>
void copy(T* dst, T* src, size_t sz, TrueType){
    cout << typeid(T).name() << ": memcpy" << endl;
    memcpy(dst, src, sizeof(T) * sz); 
}

template<class T>
void copy(T* dst, T* src, size_t sz, FlaseType){
     cout << typeid(T).name() << ": operator=" << endl;
        for(int i = 0; i < sz; i++){
            dst[i] = src[i];
        } 
}


template<class T>
void Copy(T* dst, const T* src, size_t sz){
    copy(dst, src, sz, TypeTraits<T>::isPodType() );
}






// int main()
// {
//     string arr[3] = {"111" , "333", "555"};
//     string arr2[3];
//     Copy(arr2, arr,sizeof(arr) / sizeof(arr[0]));
//     for(int i = 0; i < 3 ; i++){
//         cout << arr2[i] << endl;
//     }
//     //Test1();
//     //Test2();
//     //Test3();
//     return 0;
// }