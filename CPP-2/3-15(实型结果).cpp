/********
2021.4.12  19:11
cpp语言程序设计 3-15'
*********/
#include <iostream>
using namespace std;
int getPower(int x,int y);
double getPower(double x,int y);
int main(){
	int a,m;
	double b;
	cin>>a>>b>>m;
	cout<<getPower(a*1.0,m)<<" "<<getPower(b,m)<<endl;
	return 0;
}
double getPower(double x,int y){
	if(y==0){
			return 1.0;
		} 
	double s=1.0;
	if(y<0){
		for(int i=1;i<=-y;i++){
				s*=x;
			}			
			return 1.0/s;
		}else{
			for(int i=1;i<=y;i++){
					s*=x;
				}
			return s;
		}
}
