/********
2021.4.12  18:44 
cpp语言程序设计 3-7 
*********/
#include <iostream>
using namespace std;
short int divd(unsigned short int a,unsigned short int b);
int main(){
	int a,b;
	cin>>a>>b;
	short int c=divd(a,b);
	cout<<c<<endl;
	return 0;
}
short int divd(unsigned short int a,unsigned short int b){
	if(b==0){
		return -1;
	}else{
		return a/b;
	}
}
