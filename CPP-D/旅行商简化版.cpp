/*
题目背景
J.L.Bentley提出了一种叫做bitonic tour的哈密尔顿环游。
它的要求是任意两点(a,b)之间的相互到达的代价dist(a,b)=dist(b,a)且任意两点之间可以相互到达，
并且环游的路线只能是从最西端单向到最东端，再单项返回最西端，并且是一个哈密尔顿回路。

题目描述
现在笛卡尔平面上有n(n<=1000)个点，每个点的坐标为(x,y)(-2^31<x,y<2^31，且为整数)，
任意两点之间相互到达的代价为这两点的欧几里德距离，现要你编程求出最短bitonic tour。

输入格式
第一行一个整数n,接下来n行，每行两个整数x,y，表示某个点的坐标。
输入中保证没有重复的两点，保证最西端和最东端都只有一个点。

输出格式
一行，即最短回路的长度，保留2位小数。

时间限制
1.00s

内存限制
125.00MB

2021.5.23

*/ 
#include <bits/stdc++.h>											//包含大部分常用函数的头文件 
#define fu(i,a,b) for(register int i=a;i<=b;i++)					//宏定义步长为1的增循环 
#define fd(i,a,b) for(register int i=a;i>=b;i--)					//宏定义步长为1的减循环 

using namespace std;
const int MAX = 1005;												//输入数据个数n的最大值为1000，不妨设MAX为1005，防止定义数组时数据溢出 
int n;
struct point{														//结构体点，具有为整数的横纵坐标 
	//int x,y;距离计算需要进行次方运算，定义整形容易导致溢出
	long long x,y; 
}p[MAX];
bool cmp(point a,point b){											//sort函数排序结果依照x的大小进行排序 
	return a.x<b.x;
}
double dis(point a,point b){										//求两点间距离的函数 
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double d[MAX][MAX];
/*
	double f(int i,int j){											 //由于所求为哈密顿回路，即起点终点已知且每一个结点均需经过 ，
		if(p[j].x>=p[i].x){                                          //可看作由起点出发，横坐标只能增加无法减少的两条路径，且两条路径需经过所有点并
			return 0.0;												 //最终于终点汇合。题目所求即两条路径之和的最小值。
		}else{
			 if(p[i].x==p[n-1].x){
			 	return dis(p[i],p[n])+dis(p[j],p[n]);
			 }else{
			 	return min(dis(p[i],p[i+1])+f(i+1,j),dis(p[j],p[i+1])+f(i+1,i));
			 }
		}
	}
	递归算法导致时间超过题目限制 
*/
 																	  //不妨设f（i，j），其中i>j,f为在已经过p[1]到p[j]中的所有点时，
																	  //两者距p[n]的距离之和的最小值。
																	  //由于每个点均需要经过且横坐标只能增加，故一定存在p[i]-p[i+1]或p[j]-p[i+1]两条 
																	  //路径中的一条，故可列出状态转移函数如下： 
																	  //f（i，j）=min{[dis(i,i+1)+f(i+1,j)],[dis(j,i+1)+f(i+1,i)]} 
																	  //若j与i之间存在未达到的点且 [dis(j,i+1)+f(i+1,i)]> [dis(i,i+1)+f(i+1,j)],
																	  //则在f(i+1,i)中路径会被改写为 i所在路径经过了j与i之间的点
																	  //逆推可知所求为dis(1,2)+f(2,1) 
																	  //顺推至n可知边界为f(n-1,j)= dis(n-1,n)+dis(j,n)
	
int main(){
	freopen("test1.txt","r",stdin);
	memset(d,0.0,sizeof(d));
	cin>>n;
	fu(i,1,n){
		cin>>p[i].x>>p[i].y;
	}
	sort(p+1,p+n+1,cmp);
/*
	fu(i,1,n){
		cout<<p[i].x;
	}
*/	 		
	fd(i,n-2,1){													   //通过二重循环对二维数组进行赋值以规避递归层数过多用时过久	
		d[n-1][i]=dis(p[n-1],p[n])+dis(p[i],p[n]);					   //对 f(n-1,i)初始化，根据定义可知满足已经过p[1]到p[i]所有点时两者距p[n]的最小值即为 
	}																  //dis(n-1,n)+dis(i,n) 
	fd(i,n-2,2){												  	 //由于所有 f(n-1,i)已知，故只需通过状态转移方程逆序求出f(n-2,i),f(n-3,i)……一直到f(2,i) 
		fu(j,1,i-1){
			d[i][j]=min(dis(p[i],p[i+1])+d[i+1][j],dis(p[j],p[i+1])+d[i+1][i]);
		}
	}
	double s=dis(p[1],p[2])+d[2][1];
	printf("%.2lf\n",s);                                                                  				 
																	 
	return 0;
}

/*
以下是生成横坐标不重复的点的代码 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("test2.txt","w",stdout);
	int n;
	cin>>n;
	cout<<n<<endl; 
	int x[n],y[n];
	srand((int)time(0));												//生成真随机数 
 	int a[n];
 	for(int i=0;i<n;i++){
	 	a[i]=pow((-1),(rand()%2+1))*i*(rand()%514+1);					//生成正负兼有的横坐标 
	}
	int index;
 	for(int i=0;i<n;i++){
 		index=(int)((float)(n-i)*rand()/(RAND_MAX+1.0)); 				//生成不大于n-i的随机下标 
  		x[i]=a[index];
  		y[i]=(int)rand()*19260817/114;									//生成正负兼有的纵坐标 
  		a[index]=a[n-1-i];												//回收已经用过的下标，防止重复生成相同横坐标 
   		cout<<x[i]<<" "<<y[i]<<endl; 
 	}
 	return 0;
}
*/ 
