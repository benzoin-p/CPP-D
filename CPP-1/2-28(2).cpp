/********
2021.3.29  22:38 
cpp语言程序设计 2-28（2） 
*********/
#include <iostream>
using namespace std;
int main(){
	char userInput;
	cout<<"Menu: A(dd) D(elete) S(ort) Q(uit) ,Select one:"<<endl;
	for(;;){
		cin>>userInput;
		switch(userInput){
			case 'A':
				cout<<"数据已经增加"<<endl;
				break;
			case 'D':
				cout<<"数据已经删除"<<endl;
				break;
			case 'S':
				cout<<"数据已经排序"<<endl;
				break;
			case 'Q':
				return 0;
			default:
				break;
		}
	}
	return 0;
}
