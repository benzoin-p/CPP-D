/********
2021.4.12  18:49
cpp语言程序设计 3-13 
*********/
#include <iostream>
using namespace std;
int fibonacci(int n);
int main(){
	int n;
	cin>>n;
	cout<<fibonacci(n)<<endl;
	return 0;
}
int fibonacci(int n){
	if(n==1||n==2){
		return 1;
	}else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}
