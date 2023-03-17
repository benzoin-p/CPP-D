/********
2021.3.29  22:32 
cpp语言程序设计 2-28（1） 
*********/
#include <iostream>
using namespace std;
int main(){
	char userInput;
	cout<<"Menu: A(dd) D(elete) S(ort) Q(uit) ,Select one:"<<endl;
	for(;;){
		cin>>userInput;
		if(userInput=='A'){
				cout<<"数据已经增加"<<endl;
				continue;
			}else if(userInput=='D'){
				cout<<"数据已经删除"<<endl;
				continue;
			}else if(userInput=='S'){
				cout<<"数据已经排序"<<endl;
				continue;
			}else if(userInput=='Q'){
				break;
			}else{
				continue;
			}
	}
	return 0;		 
}
