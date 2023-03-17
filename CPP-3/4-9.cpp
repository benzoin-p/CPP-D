/********
2021.4.27  11:28 
cpp语言程序设计 4-9 
*********/
#include <iostream>
using namespace std;
class Point{
	public:
		Point(int xx,int yy);
		Point(Point &p);
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
	private:
		int x,y;
};
class Rectangle{
	public:
		Rectangle(Point p1,Point p2);
		Rectangle(Rectangle &r);
		int getArea();
	private:
		Point a,b;
};

Point::Point(int xx=0,int yy=0){
	x=xx;
	y=yy;
}
Point::Point(Point &p){
	x=p.x;
	y=p.y;
}
Rectangle::Rectangle(Point p1,Point p2){
	a=p1;
	b=p2;
}
Rectangle::Rectangle(Rectangle &r):a(r.a),b(r.b){
	a=r.a;
	b=r.b;
}
int Rectangle::getArea(){
	int t =abs((a.getX()-b.getX())*(a.getY()-b.getY()));
	return t;
}
int main(){
	int tp1x,tp1y,tp2x,tp2y;
	cout<<"enter the x and y of the point1 and point2:";
	cin>>tp1x>>tp1y>>tp2x>>tp2y;
	Point tp1(tp1x,tp1y),tp2(tp2x,tp2y);
	Rectangle tr(tp1,tp2);
	cout<<"the rectangle's area is:"<<tr.getArea()<<endl;
	return 0;
}
	
