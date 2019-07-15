// 斗地主(landlords) (http://www.mfstem.org/contest/21/problem/C)
// author: kelvin
// status: AC
#include <bits/stdc++.h>

using namespace std;

int n,T,d[5],c[20],a,b,kin,ans,tot,mn;

int gao()
{
    int res=0,e[5];memcpy(e,d,sizeof(e));//做完之后要还原，备份一份d数组
    while(d[4])
    {
        if(d[1]<2&&!d[2]) break;//不能四带二了
        if(d[1]>=2) d[4]--,d[1]-=2,res++;//带两个单牌
        else if(d[2]>=2) d[4]--,d[2]-=2,res++;//带两个对子
        else if(d[2]==1) d[4]--,d[2]--,res++;//带一个对子（优先级最低）
    }
    while(d[3])
    {
        if(!d[1]&&!d[2]) break;//不能三带了
        if(d[1]) d[3]--,d[1]--,res++;//带一个单牌
        else if(d[2]) d[3]--,d[2]--,res++;//带一个对子
    }
    int g=d[1]+d[2]+d[3]+d[4]+res;//总出牌次数
    memcpy(d,e,sizeof(e));return g;//还原
}

void dfs2()
{
    tot=min(tot,gao());//即时统计答案
    if(d[3]) d[3]--,d[1]++,d[2]++,dfs2(),d[3]++,d[1]--,d[2]--;//把三张牌拆成一个单牌和一个对子（33344445555）
    if(d[4]) d[4]--,d[2]++,d[2]++,dfs2(),d[4]++,d[2]--,d[2]--;//把四张牌拆成两个对子（33334444）
    if(d[4]) d[4]--,d[1]++,d[3]++,dfs2(),d[4]++,d[1]--,d[3]--;//把四张牌拆成一个单牌和一个三对（33334444556）
}

void dfs1(int val)
{
    memset(d,0,sizeof(d));for(int i=2;i<=16;i++) d[c[i]]++;//统计不同大小的牌的出现次数
    tot=1e9;dfs2();ans=min(ans,val+tot);//即时更新答案
    for(int i=3;i<=10;i++) if(c[i]>=1) for(int j=i+1;j<=14;j++)//出单顺
    {
        if(c[j]<1) break;if(j-i<4) continue;
        for(int k=i;k<=j;k++) c[k]-=1;dfs1(val+1);for(int k=i;k<=j;k++) c[k]+=1;
    }
    for(int i=3;i<=12;i++) if(c[i]>=2) for(int j=i+1;j<=14;j++)//出双顺
    {
        if(c[j]<2) break;if(j-i<2) continue;
        for(int k=i;k<=j;k++) c[k]-=2;dfs1(val+1);for(int k=i;k<=j;k++) c[k]+=2;
    }
    for(int i=3;i<=13;i++) if(c[i]>=3) for(int j=i+1;j<=14;j++)//出三顺
    {
        if(c[j]<3) break;if(j-i<1) continue;
        for(int k=i;k<=j;k++) c[k]-=3;dfs1(val+1);for(int k=i;k<=j;k++) c[k]+=3;
    }
}

int main()
{
	// freopen("landlords.in", "r", stdin);
	// freopen("landlords.out", "w", stdout);
    for(scanf("%d%d",&T,&n);T--;)
    {
        memset(c,0,sizeof(c));mn=1e9;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a==0&&b==1) c[15]++;
            else if(a==0&&b==2) c[16]++;//大小王
            else if(a==1) c[14]++;
            else if(a>1) c[a]++;//对A进行处理，方便出顺子
        }
        kin=min(c[15],c[16]);
        c[15]-=kin;c[16]-=kin;//出王炸（333大小王）
        ans=1e9;dfs1(0);mn=min(mn,kin+ans);
        c[15]+=kin;c[16]+=kin;//不出王炸（3333大小王）
        ans=1e9;dfs1(0);mn=min(mn,ans);
        printf("%d\n",mn);
    }
	return 0;
}