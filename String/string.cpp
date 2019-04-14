#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class String{
public:
	String()
	:_str(new char[1])
	{
		_str[0] = '\0'
	}
	
	const char* c_str(){
		return _str;
	}	
	
	//带参构造，需要申请和输入字符串一样大的空间
	//把输入字符串拷贝进去
	//如果只拷贝字符串指针
	//释放可能会有问题： 1.二次释放（两个指针同时指向同一片空间），
	//                2.如果传入的为字符串常量，析构就会崩溃（不能主动释放代码段的字符串常量）
	String(char* str)
	:_str(new char[strlen(str) + 1])
	{
		strcpy(_str,str);
	}
	
	//全缺省构造函数，缺省值为”“
	String(char* str = " ")
	:_str(new char[strlen(str) + 1])
	{
		strcpy(_str,str);
	}
	
	
	//拷贝构造（深拷贝） 1，申请空间，2 拷贝内容
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str,s._str);
	}
	
	//现代写法:
	//自己不申请空间，不拷贝
	//通过调用构造函数，生成了一个新的临时对象
	//直接获取临时对象的全部内容（通过交换指针完成），完成当前对象的拷贝构造
	String(const String& s)
	:_str(nullprt)
	{
		String tmp(s._str);
		swap(_str,tmp._str);
	}
	
	//传统写法 赋值运算符
	//返回引用，为了连续赋值
	
	//要拷贝的字符串长度不一定和当前对象的字符串长度一致
	//如果直接拷贝，空间不足的时候，会导致数据丢失
	//所以直接释放原有空间，申请一个和当前要拷贝的字符串一样大的空间
	//——str至少有一个字节的空间，由构造函数保证
	String& operator=(const String&s){
		if(this != &s){
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str,s._str);
		}
	}
	
	//现代写法：代码复用，简洁
	//传入参数：传值，并不会引发赋值运算符无穷递归，通过调用拷贝构造完成值拷贝
	//传值相当于在函数栈桢中生成一个临时对象
	//和拷贝构造相比，
	//不需要检查是否自己赋值，因为在赋值之前，没有空间释放的操作
	String& operator=(String s){
		swap(_str,s._str);
		return *this;
	}
	
	～String(){
		if(_str){
			delete[] _str;
			_str = nullptr; 
		}
	}
	
	
private:
	char* _str;
	
};



class String{
public:
	typedef char* Iterator;
	
	//无参构造函数
	//siza == 0；
	//capacity == 0
	String()
	:_size(0)
	,_capacity(0)
	,_str(new char[1])
	{
		_str[0] = '\0';
	}
	
	//返回c类型的字符串
	const char* c_str(){
		return _str;
	}	
	
	
	//构造函数
	String(char* str)
	:_size(strlen(str))
	,_capacity(_size + 1)
	,_str(new char[_size + 1])
	{
		strcpy(_str,str);
	}
	
	//全缺省构造函数，缺省值为”“
//	String(char* str = "")
//	:_size(strlen(str))
//	,_capacity(_size + 1)
//	,_str(new char[_size + 1])
//	{
//		strcpy(_str,str);
//	}
	
	
	//拷贝构造（深拷贝） 1，申请空间，2 拷贝内容
//	String(const String& s)
//		:_size(s._size)
//		,capacity(s._capacity)
//		,_str(new char[_size + 1])
//	{
//		strcpy(_str,s._str);
//	}
	
	
	//现代写法:
	String(const String& s)
	:_str(nullptr)                        //！！！这里面给str付了一个初值nullptr，真很重要，如果不给nullptr，这其中的str会放一个随机值
	{                                     //在与tmp交换的时候tmp中的str就会放一个随机值，在释放的时候释放一个随机值会有问题
		String tmp(s._str);
		swap(_str,tmp._str);
	}
	
	//传统写法 赋值运算符
//	String& operator=(const String&s){
//		if(this != &s){
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str,s._str);
//		}
//	}
	
	//现代写法
	String& operator=(String s){
		swap(_str,s._str);
		return *this;
	}
	
	//析构函数
	~String(){
		if(_str){
			delete[] _str;
			_str = nullptr; 
		}
	}
	
	//增容
	void Reverse(size_t new_capacity ){
		if(new_capacity == 0){
			_capacity = 15;
			return;
		}
		
		_capacity = new_capacity;
		return;
		
	}
	
	//尾插
	void PushBack(const char c){
		if(_size == _capacity){
			Reverse(2 * _capacity);
		}
		
		_str[_size] = c;
		_size++;
		_str[_size] = '\0';
		
	}
	
	//iterator
	Iterator Begin(){
		return _str;
	}
	
	Iterator End(){
		return _str + _size;
	}
	
	const Iterator Begin() const{
		return _str;
	}
	
	const Iterator End() const{
		return _str + _size;
	}
	
	void Append(const char* str){
		if(strlen(str) + _size > _capacity){
			Reverse(_size + strlen(str));
		}
		
//		while(strlen(str) + _size > _capacity){
//			Reverse();
//		}
		
		strcpy(_str + _size, str);
		_size += strlen(str);
	}
	
	void ReSize(size_t n, char c = '\0'){
		if(n > _size){
			if(n > _capacity){
				Reverse(n);
			}
			memset(_str + _size, c, n - _size);
		}
		
		_size = n;
		_str[_size] = '\0';
	}
	
	void Insert(size_t pos,const char c){
		assert(pos <= _size);
		
		if(_size == _capacity){
			//Reverse(_capacity + 1);
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity); 
			Reverse(newC);
		}
		
		int i = _size;
		for(i = _size; i > pos ; i--){
			_str[i] = _str[i - 1];
		}
		
		_str[pos] = c;
		_str[++_size] = '\0';
	}
	
	void Insert(size_t pos,const char* str){
		assert(pos <= _size);
		int sz = strlen(str);
		if(_size + sz > _capacity){
			size_t newC = (_capacity == 0 ? 15 : _size + sz);
		}
		
		int i = _size + sz - 1;
		while(i > pos + sz){
			_str[i] = _str[i - sz];
			i--;
		}
		
		int j = 0;
		while(j < sz){
			_str[pos] = str[j];
			pos++;
			j++;
		}
		
		_size = _size + sz;
		_str[++_size] = '\0';
	}
	
	void Erase(size_t pos, size_t len){
		assert(pos < _size);
		if(pos + len > _size){
			_size = pos;
			_str[_size] = '\0';
		}
		else{
			size_t start = pos + len;
			while(start < _size){
				_str[pos++] = _str[start++];
			}
			
		_size -= len;
		_str[_size] = '\0';
	}
}

private:
	size_t _size;
	size_t _capacity;
	char* _str;
	
};



char* strstr(char* dest, char* substr)
{	
	char* str1 = dest;
	char* str2 = substr;
	
	while(*str1){
		if(*str1 == *str2){
			while(*str2 && *str1){
				if(*str1 == *str2){
					str1++;
					str2++;
				}  
			}
			if(*str2 == '\0'){
				return dest;
			}
		}
		dest++;
		str1 = dest;
		str2 = substr;
	}	
	
	return nullptr;
	
}


String operator+(const String& s1, const String& s2){
	return new String(Append(s1._str, s2._str));
}

String operator+(const String s1, const char* s2){
	String s3(s1);
	s3 += s2;
	return s3;
}

void TestStrstr(){
	char* str1 = "hello bit";
	char* str2 = "bit";
	strstr(str1,str2);
	
}


void TestString(){
	String s("abc");
	s.PushBack('w');
	s.PushBack('y');
	s.PushBack('h');
	s.Append("xxxxxx");
}



