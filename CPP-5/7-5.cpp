/********
2021.6.2  18:48
cpp语言程序设计 7-5 
*********/
#include <iostream>
using namespace std;
const double PI = 3.14;
class Shape{
	public:
		Shape(){};
};
class Rectangle:public Shape{
	public:
		Rectangle(double a,double b);
		double getArea();
	private:
		double a,b;
		double area;
};
		
class Circle:public Shape{
	public:
		Circle(double r);
		double getArea();
	private:
		double r;
		double area;
};
class Square:public Rectangle{
	public:
		Square(double l);
		double getArea();
	private:
		double l;
		double area;
};
Rectangle::Rectangle(double a,double b){
	this->a=a;
	this->b=b;
}
double Rectangle::getArea(){
	this->area=a*b;
	return area;
}
Circle::Circle(double r){
	this->r=r;
}
double Circle::getArea(){
	this->area=PI*r*r;
	return area;
}
Square::Square(double l):Rectangle(l,l){
	this->l=l;
}
double Square::getArea(){
	this->area=l*l;
	return area;
}
int main(){
	Rectangle r1(4.5,5.5);
	cout<<"The area of the rectangle is "<<r1.getArea()<<endl;
	Circle c1(2);
	cout<<"The area of the circle is "<<c1.getArea()<<endl;
	Square s1(1.2);
	cout<<"The area of the square is "<<s1.getArea()<<endl;
	return 0;
}
