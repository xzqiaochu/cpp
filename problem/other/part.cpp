#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int X=0,w=1; char ch=0;
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}/*���*/

int tu[2050][2050],sum1,sum,num,sum2,delta[2050],f[2050];
vector<int>lb[2050];/*�������ڽӾ����һ�³�ʼ��ͼ��Ȼ����vector��һ�²�ͼ*/
int n,col[2050],v[2050];
void dfs(int x,int cols){/*����dfsд��dfn��233*/
    if(v[x]&&col[x]!=cols){
        cout<<"No solution";
        exit(0);
}/*������ʹ�����������㣬����Ⱦ����ɫ�����ϻ�Ⱦ�Ĳ�һ����˵��Ⱦ����GG*/

    if(v[x])return;
    v[x]=1;/*���*/
    col[x]=cols;/*Ⱦɫ*/
    if(col[x]==1)sum1++;
    else sum2++;/*����*/
    for(int i=0;i<lb[x].size();i++){
        int u=lb[x][i];
        int colss=cols==1?2:1;/*���ý����˰�...*/
        dfs(u,colss);/*������x���ӵĵ㣬��Ⱦ��colss*/
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
}/*�й��оصĶ���*/

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(!(tu[i][j]*tu[j][i])){
                lb[i].push_back(j);
                lb[j].push_back(i);
            }
        }
}/*���i��j��j��i��ֻ��һ�����µ�·��ͨ�Ļ�˵�����ǲ�����ͬһ�飬���벹ͼ����*/

    for(int i=1;i<=n;i++){
        if(!col[i]){
        num++;/*����õ�û��Ⱦ��ɫ����Ⱦ*/
        sum1=0;/*ע���������*/
        sum2=0;
        dfs(i,1);
        delta[num]=max(sum1,sum2)-min(sum1,sum2);
        sum+=delta[num];/*"��ͼ�������ɸ���ͨ�飬���԰�ÿ����ͨ�鵱��һ����Ʒ������Ȩֵ�ͱ�ʾ������ɫ֮�"��仰��ʵ��*/
        }
}/*���������ת����һ���򵥵ı�������*/

    int t=sum/2;
    for(int i=1;i<=num;i++){
        for(int j=t;j>=delta[i];j--){
            f[j]=max(f[j],f[j-delta[i]]+delta[i]);
        }
    }
    int ans=max(sum-f[t],f[t])-min(sum-f[t],f[t]);
    cout<<((n-ans)/2)<<" "<<((n+ans)/2);
}
