/********
2021.5.18  22:10 
cpp语言程序设计 5-7 
*********/
#include <iostream>
using namespace std;
class Cat{
	public:
		static int getNumOfCats(){
			return numOfCats;
		}
		Cat(){
			numOfCats++;
			cout<<"A cat has been created!"<<endl;
		}
	private:
		static int numOfCats;
};
int Cat::numOfCats=0;
int main(){
	Cat cat1;
	cout<<"There is "<<Cat::getNumOfCats()<<" cat!"<<endl;
	Cat cat2;
	cout<<"There are "<<Cat::getNumOfCats()<<" cats!"<<endl;
	return 0;
}
