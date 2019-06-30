#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int X=0,w=1; char ch=0;
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}/*快读*/

int tu[2050][2050],sum1,sum,num,sum2,delta[2050],f[2050];
vector<int>lb[2050];/*我们用邻接矩阵存一下初始的图，然后用vector存一下补图*/
int n,col[2050],v[2050];
void dfs(int x,int cols){/*他把dfs写成dfn了233*/
    if(v[x]&&col[x]!=cols){
        cout<<"No solution";
        exit(0);
}/*如果访问过，并且这个点，即将染的颜色与他上回染的不一样，说明染糊了GG*/

    if(v[x])return;
    v[x]=1;/*标记*/
    col[x]=cols;/*染色*/
    if(col[x]==1)sum1++;
    else sum2++;/*计数*/
    for(int i=0;i<lb[x].size();i++){
        int u=lb[x][i];
        int colss=cols==1?2:1;/*不用解释了吧...*/
        dfs(u,colss);/*遍历与x连接的点，并染成colss*/
    }
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        tu[i][i]=1;
        int x;
        do{
            x=read();
            if(x!=0)
                tu[i][x]=1;
        }while(x!=0);
}/*中规中矩的读入*/

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(!(tu[i][j]*tu[j][i])){
                lb[i].push_back(j);
                lb[j].push_back(i);
            }
        }
}/*如果i到j，j到i中只有一条以下的路联通的话说明他们不能在同一组，加入补图当中*/

    for(int i=1;i<=n;i++){
        if(!col[i]){
        num++;/*如果该点没有染过色，就染*/
        sum1=0;/*注意计数清零*/
        sum2=0;
        dfs(i,1);
        delta[num]=max(sum1,sum2)-min(sum1,sum2);
        sum+=delta[num];/*"补图会有若干个连通块，可以把每个连通块当做一个物品，它的权值就表示两种颜色之差。"这句话的实现*/
        }
}/*这里把问题转化成一个简单的背包问题*/

    int t=sum/2;
    for(int i=1;i<=num;i++){
        for(int j=t;j>=delta[i];j--){
            f[j]=max(f[j],f[j-delta[i]]+delta[i]);
        }
    }
    int ans=max(sum-f[t],f[t])-min(sum-f[t],f[t]);
    cout<<((n-ans)/2)<<" "<<((n+ans)/2);
}
