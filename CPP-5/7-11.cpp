/********
2021.6.2  18:57
cpp语言程序设计 7-11
*********/
#include <iostream>
using namespace std;
class BaseClass{
	public:
		void fn1();
		void fn2();
};
class DerivedClass:public BaseClass{
	public:
		void fn1();
		void fn2();	
};
void BaseClass::fn1(){
	cout<<"The fn1 in BaseClass is called"<<endl;
}
void BaseClass::fn2(){
	cout<<"The fn2 in BaseClass is called"<<endl;
}
void DerivedClass::fn1(){
	cout<<"The fn1 in DerivedClass is called"<<endl;
}
void DerivedClass::fn2(){
	cout<<"The fn2 in DerivedClass is called"<<endl;
}
int main(){
	DerivedClass instance;
	DerivedClass* p= &instance;
	BaseClass* psuper=&instance;
	instance.fn1();
	instance.fn2();
	p->fn1();
	p->fn2();
	psuper->fn1();
	psuper->fn2();
	return 0;
}
