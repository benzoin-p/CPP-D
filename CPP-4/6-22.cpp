/********
2021.5.18  23:12
cpp语言程序设计 6-22
*********/
#include <bits/stdc++.h> 
using namespace std;
string rs;
void reverse(string &s){
	if(s.length()==1){
		rs+=s;
		return;
	}else{
		string ts=s.substr(0,s.length()-1);
		rs+=s.substr(s.length()-1,1);
		reverse(ts);
		return;
	}
}
int main(){
	string s;
	cout<<"enter a string:";
	cin>>s;
	reverse(s);
	cout<<"reversed string is "<<rs<<endl;
	return 0; 
}
