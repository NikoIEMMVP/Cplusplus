#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;


// ************* 初始化列表  *********************
#if 0
template<class T>
class Vector
{
public:
   // 阻止单参数隐式类型转换
   // explicit Vector(int n)
   // :_start(new T[n]){

   // }

   Vector(int n)
   :_start(new T[n]){

   }

   //initializer_list
   Vector(initializer_list<T> lst):_start(new T[lst.size()]){
      int sz = 0;
      for(const auto& e : lst){
         _start[sz++] = e;
      }
   }
   // Vector& Vector(Vector& v){

   // }


private:
   T* _start;
};

int main()
{
   // 初始化列表
   int a[] = {1,2,3,4};
   vector<int> v1;
   vector<int> v2(10,1);
   vector<int> v3(a, a+4);

   // C++11
   int i = {1};
   int i2{2};
   vector<int> v = {1,2,3,4};
   list<int> lst = {4,5,6,7};
   map<int,int> m = {{1,1}, {2,2},{3,3}};

   // 单对象创建，编译器默认支持初始化列表
   Vector<int> v4 = {10}; // 单参数构造函数隐式类型转换
   // 多对象创建，实现接受初始化列表（initializer_list）的构造函数
   Vector<int> v5 = {1,1,1,1}; // 初始化列表






   return 0;
}

#endif


// ************************ 类型推导 *************************
#if 0

int fun1(int i){
   return 1;
}


void test1(){
   // 编译时要确定变量类型
   auto i = 10;

   std::map<std::string, std::string> map;
   std::map<std::string, std::string>::iterator it = map.begin();
   auto it2 = map.begin();


   // 运行时根据表达式结果推导变量类型
   decltype(1 + 2) a;  // RTTI
   // 根据函数返回值类型推导变量类型
   decltype(fun1(4)) b;


   // **************************** final ******************************8
   // 定义类：不能被继承
   // 定义函数：函数不能被重写 --> 实现继承
   // **************************** override *************************
   // 虚函数 + override：子类必须重写父类的一个虚函数 --> 接口继承


}







#endif



// *************************** 委派构造函数 *************
// 构造函数之间可以相互调用，可以减少构造函数代码的冗余
// 在初始化列表中，如果使用的委派构造函数，就不能再加成员的初始化（两者互斥）
#if 0

class B{
public:
   B():_a(1), _b(2), _c(3), _d(4){

   }
   
   // B(int a):_a(a), _b(2), _c(3), _d(4){

   // }

   B(int a):B(){
      _a = a;
   }

   // B(int a, int b):_a(a), _b(b), _c(3), _d(4){

   // }

   B(int a, int b):B(a){
      _b = b;
   }


private:
   int _a;
   int _b;
   int _c;
   int _d;
};


#endif


#if 1

// ******************* 右值引用 ****************


int fun2(){
   int a = 10;

   return a;
}


void test2(){

   // a,b,c,10,fun2的返回值

   // 左值：既可以出现在赋值符号的左边，也可以出现在赋值符号的右边，或者说可以取地址的

   // a,b,c
   // （老概念）右值：只能出现在赋值符号的右边，或者说不是左值的都是右值
   // （新概念）右值：常量，临时变量，将亡值（生命周期马上要结束了）
   // 10,fun2的返回值
   int a;
   int b = 10;
   int c = a;

   int d = fun2();

   // 左值引用：可以引用左值，可以引用右值
   int& ra = a;

   // int& rra = 10; 这样不行
   const int& rra = 10;
   const int& r1 = fun2();

   // 右值引用：只能引用右值，不能引用左值
   int&& ra1 = 10;
   int&& ra2 = fun2();
   // int&& ra3 = a;    a 是左值，不行


}






#endif