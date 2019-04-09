#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100005;
int count[N];//count[i]记录能通过乘2或除2变成i的数的个数 
int ans[N];//ans[i]统计n个数变成i总共需要的步数
void convert(int n,int step) {
	//乘2
	for(int i=n;i<N;i*=2,step++)
	{
		count[i]++;
		ans[i]+=step;
	}
} 
int main(){
	int n,x,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&x);
		convert(x,0);
		int step=0; 
		while(x/2>0) {
			if(x%2==1)//如果x是奇数，要考虑x/2 不断乘2的扩展
			  convert(x/2,++step);
			else//如果x是偶数的话就，只用考虑x/2这个数  
			{
				count[x/2]++;
				ans[x/2]+=(++step);
			}
			x/=2; 
		}
		res+=(++step);//统计各个数变成0的步数 
	}
	for(int i=1;i<N;i++)
	  if(count[i]==n)//如果n个数都能变换为i，则更新答案 
	  	res=min(res,ans[i]);
	printf("%d\n",res);
	return 0;
}