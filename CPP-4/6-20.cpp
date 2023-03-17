/********
2021.5.18  22:38
cpp语言程序设计 6-20 
*********/
#include <iostream>
using namespace std;
class SimpleCircle{
	public:
		SimpleCircle(int a=5);
		int getRadius();
	private:
		int* itsRadius;
};
int SimpleCircle::getRadius(){
	return *itsRadius;
}
SimpleCircle::SimpleCircle(int a){
	itsRadius=new int(a);
}
int main(){
	SimpleCircle c1;
	SimpleCircle c2(9);
	cout<<"The radius of c1 is "<<c1.getRadius()<<endl;
	cout<<"The radius of c2 is "<<c2.getRadius()<<endl;
	return 0;
}
