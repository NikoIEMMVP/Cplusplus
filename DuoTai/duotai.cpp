#include <iostream>
#include <stdlib.h>

using namespace std;

#include <iostream>
#include <stdlib.h>

using namespace std;

class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};

class Student : public Person
{
public:
	void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
};


void Fun(Person& p)
{
	p.BuyTicket();
}



int main()
{
	Person p;
	Student s;

	Fun(p); 
	Fun(s);

	person p1;
	student s1;
	person* p = &p1;
	person* s = &s1;

	p->buyticket();
	s->buyticket();

	system("pause");
	return 0;
}

class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}

private:
	int _a;
};

class Student : public Person
{
public:
	virtual ~Student()
	{
		cout << "~Student()" << endl;
	}
private:
	int _b;
};


int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;

	delete p1;
	delete p2;

	system("pause");
	return 0;
}

class A
{
public:
	virtual void Fun1()
	{
		cout << "A - Fun1()" << endl;
	}

	virtual void Fun2()
	{
		cout << "A - Fun2()" << endl;
	}

	virtual void Fun3()
	{
		cout << "A - Fun3()" << endl;
	}

private:
	int _a = 1;
};

class B : public A
{
public:
	virtual void Fun1()
	{
		cout << "B - Fun1()" << endl;
	}

	virtual void Fun4()
	{
		cout << "B - Fun4()" << endl;
	}

	void Fun2()
	{
		cout << "No_virtual - B - Fun2()" << endl;
	}

private:
	int _b = 3;
};

int main()
{
	A a;
	B b;


	system("pause");
	return 0;
}

class A
{
public:
	virtual void Fun1()
	{
		cout << "A-Fun1()" << endl;
	}

	virtual void T(){
		cout << "A-Fun1()" << endl;

	}

	A& operator = (const B b)
	{
		*(int*)this = * (int*) &b;
		return *this;
	}
};

class B : public A
{
public:
	virtual void Fun1()
	{
		cout << "B-Fun2()" << endl;
	}
};

int main()
{
	A a;
	B b;

	a = b;
	a.Fun1();
	b.Fun1();
	system("pause");
	return 0;


//单继承中的虚表函数
class Base
{
public:
	virtual void fun1()
	{
		cout << "Base::fun1()" << endl;
	}

	virtual void fun2()
	{
		cout << "Base::fun2()" << endl;
	}
private:
	int _a = 1;
};

class Derive : public Base
{
	virtual void fun1()
	{
		cout << "Derive::fun1()" << endl;
	}

	virtual void fun3()
	{
		cout << "Derive::fun3()" << endl;
	}

	virtual void fun4()
	{
		cout << "Derive::fun4()" << endl;
	}

private:
	int _b = 2;
};

typedef void(*VFPTR) ();

void PrintVftable(VFPTR vTable[])
{
	cout << "虚表地址： " << vTable << endl;

	for (int i = 0; vTable[i] != nullptr; i++)
	{
		printf("第%d个虚函数地址: 0x%x -->", i + 1, vTable[i]);
		VFPTR v = vTable[i];
		v();
		cout << endl;
	}        
	cout << endl;
}

int main()
{
	Base b;
	Derive d;

	VFPTR* vTable1 = (VFPTR*)(*(int*)&b);
	PrintVftable(vTable1);

	VFPTR* vTable2 = (VFPTR*)(*(int*)&d);
	PrintVftable(vTable2);

	system("pause");
	return 0;
}


//多继承中的虚表函数
class Base1
{
public:
	virtual void fun1()
	{
		cout << "Base1::fun1()" << endl;
	}

	virtual void fun2()
	{
		cout << "Base1::fun2()" << endl;
	}
private:
	int _a = 1;
};

class Base2
{
public:
	virtual void fun1()
	{
		cout << "Base2::fun1()" << endl;
	}

	virtual void fun2()
	{
		cout << "Base2::fun2()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base1,public Base2
{
public:
	virtual void fun1()
	{
		cout << "Derive::fun1()" << endl;
	}

	virtual void fun3()
	{
		cout << "Derive::fun3()" << endl;
	}

private:
	int _c = 2;
};

typedef void(*VFPTR) ();

void PrintVftable(VFPTR vTable[])
{
	cout << "虚表地址： " << vTable << endl;

	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址: 0x%x -->", i, vTable[i]);
		VFPTR v = vTable[i];
		v();
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Derive d;

	/*VFPTR* vTable1 = (VFPTR*)(*(int*)&b1);
	PrintVftable(vTable1);

	VFPTR* vTable2 = (VFPTR*)(*(int*)&b2);
	PrintVftable(vTable2);
*/
	VFPTR* vTable3 = (VFPTR*)(*(int*)&d);
	PrintVftable(vTable3);

	VFPTR* vTable1 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVftable(vTable1);

	cout << sizeof(d) << endl;

	Derive* p = &d;
	p->fun1();


	system("pause");
	return 0;
}