/********
2021.5.18  22:25
cpp语言程序设计 6-18 
*********/

/********
该程序未释放分配给*p的内存 
*********/
#include <iostream>
using namespace std;
int fn1(){
	int* p=new int(5);
	int a=*p;
	delete p;
	return a;
}
int main(){
	int a=fn1();
	cout<<"the value of a is:"<<a;
	return 0;
}
