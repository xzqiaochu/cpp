#include<iostream>
using namespace std;
#define maxx 1000
int a[maxx];int n;
int dfs(int cur,int num,int depth)
{
	
	for(int i=num;i<=cur/2;i++)
	{
	
		a[depth]=i;
		for(int j=1;j<=depth;j++)
		cout<<a[j]<<"+";
		cout<<cur-i<<endl;
		dfs(cur-i,i,depth+1);
		
	}
}
int main()
{
cin>>n;
dfs(n,1,1);
return 0;
}
