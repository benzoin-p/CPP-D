/********
2021.6.2  19:45
cpp语言程序设计 8-7
*********/
#include <iostream>
using namespace std;
class Point{
	public:
		Point(int x,int y);
		Point& operator++();
		Point& operator--();
		Point operator++(int);
		Point operator--(int);
		int getx(){return x;}
		int gety(){return y;}
	private:
		int x,y;
};
Point::Point(int x,int y){
	this->x=x;
	this->y=y;
}
Point& Point:: operator++(){
	x++;
	y++;
	return *this;
}
Point& Point:: operator--(){
	x--;
	y--;
	return *this;
}
Point Point:: operator++(int){
	Point t = *this;
	++ *this;
	return t;
}
Point Point:: operator--(int){
	Point t = *this;
	-- *this;
	return t;
}
int main(){
	Point a(2,3);
	Point b(2,3);
	cout<<"the value of a and b is ("<<a.getx()<<","<<a.gety()<<")"<<endl;
	b=a++;
	cout<<"after a++,the value of a is ("<<a.getx()<<","<<a.gety()<<")"<<endl;
	cout<<"after b=a++,the value of b is ("<<b.getx()<<","<<b.gety()<<")"<<endl;
	b=++a;
	cout<<"after ++a,the value of a is ("<<a.getx()<<","<<a.gety()<<")"<<endl;
	cout<<"after b=++a,the value of b is ("<<b.getx()<<","<<b.gety()<<")"<<endl;
	a--;
	cout<<"after a--,the value of a is ("<<a.getx()<<","<<a.gety()<<")"<<endl;
	--a;
	cout<<"after --a,the value of a is ("<<a.getx()<<","<<a.gety()<<")"<<endl;
	return 0;
}
