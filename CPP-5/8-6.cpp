/********
2021.6.2  19:11
cpp语言程序设计 8-6 
*********/
#include <iostream>
using namespace std;
const double PI = 3.14;
class Shape{
	public:
		Shape(){};
		~Shape(){};
		virtual double getArea()=0;
		virtual double getPerim()=0;
};
class Rectangle:public Shape{
	public:
		Rectangle(double a,double b);
		double getArea();
		double getPerim();
	private:
		double a,b;
		double area;
		double perim;
};
		
class Circle:public Shape{
	public:
		Circle(double r);
		double getArea();
		double getPerim();
	private:
		double r;
		double area;
		double perim;
};
Rectangle::Rectangle(double a,double b){
	this->a=a;
	this->b=b;
}
double Rectangle::getArea(){
	this->area=a*b;
	return area;
}
double Rectangle::getPerim(){
	this->perim=2*(a+b);
	return perim;
}
Circle::Circle(double r){
	this->r=r;
}
double Circle::getArea(){
	this->area=PI*r*r;
	return area;
}
double Circle::getPerim(){
	this->perim=2*r*PI;
	return perim;
}
int main(){
	Shape* pshape;
	pshape = new Rectangle(2.5,3.5);
	cout<<"The area of the rectangle is "<<pshape->getArea()<<endl;
	cout<<"The perim of the rectangle is "<<pshape->getPerim()<<endl;
	delete pshape;
	pshape = new Circle(2);
	cout<<"The area of the circle is "<<pshape->getArea()<<endl;
	cout<<"The perim of the circle is "<<pshape->getPerim()<<endl;
	delete pshape;
	return 0;
}
