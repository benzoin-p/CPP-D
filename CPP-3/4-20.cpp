/********
2021.4.29  0:18 
cpp语言程序设计 4-20
为啥复制构造函数存在时会将56行的代码视为复制构造函数？ 
*********/
#include <iostream>
using namespace std;
bool isZ(double a){
	if(a-(int)a==0){
		return 1;
	}else{
		return 0;
	}
}
class Complex{
	public:
		Complex(int a,int b);
		Complex(double a);		
		//Complex(Complex& c);
		void add(Complex c);
		void show();
	private:
		double a=0.0,b=0.0;
};

Complex::Complex(int a,int b){
	this->a=1.0*a;
	this->b=1.0*b;
}
Complex::Complex(double a){
	this->a=a;
}
/*
Complex::Complex(Complex& c){
	a=c.a;
	b=c.b;
}
*/
void Complex::add(Complex c){
	a=a+c.a;
	b=b+c.b;
}
void Complex::show(){
	if(isZ(a)&&isZ(b)){
			cout<<(int)a<<"+"<<(int)b<<"i"<<endl;
		}else if((!isZ(a))&&isZ(b)){
			cout<<a<<"+"<<(int)b<<"i"<<endl;
		}else if((!isZ(b))&&isZ(a)){
			cout<<(int)a<<"+"<<b<<"i"<<endl;
		}else{
		cout<<a<<"+"<<b<<"i"<<endl;
	}
}	
int main(){
	Complex c1(3,5);
	Complex c2=4.5;
	c1.add(c2);
	c1.show();
	return 0;
} 
