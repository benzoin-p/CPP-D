/********
2021.4.28  8:37 
cpp语言程序设计 4-13 
*********/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
class Circle{
	public:
		Circle(int r);
		Circle(Circle& c);
		double getArea();
	private:
		int radius;
};
Circle::Circle(int r){
	radius=r;
}
Circle::Circle(Circle& c){
	radius=c.radius;
}
double Circle::getArea(){
	return M_PI*radius*radius;
}
int main(){
	int r;
	cout<<"请输入圆的半径：";
	cin>>r;
	Circle c(r);
	printf("%s%.2f\n","圆的面积为:",c.getArea());
	return 0;
}
