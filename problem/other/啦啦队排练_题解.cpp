#include<bits/stdc++.h>
#define IL inline
#define RI register long long
#define N 1000008
#define mod 19930726
char s[N<<1],ch[N];
long long n,k,len,RL[N<<1],mxxnum,sum,ans=1;
long long MaxRight,center,tong[N<<1];
IL long long ksm(long long x,long long y)
{
    long long res=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)res=res*x%mod;
    return res;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    scanf("%s",s+1);
    for(RI i=1;i<=n;i++)
    {
        if(i<=MaxRight)RL[i]=std::min(MaxRight-i,RL[2*center-i]);
        else RL[i]=1;
        while(i+RL[i]<=n&&i-RL[i]>=0&&s[i+RL[i]]==s[i-RL[i]])++RL[i];
        if(i+RL[i]-1>MaxRight)MaxRight=i+RL[i]-1,center=i;
        tong[2*RL[i]-1]++;
    }
    //for(RI i=1;i<=n;i++)printf("%lld ",tong[i]);
    if(n%2!=1)n--;
    for(RI i=n;i>=1;i-=2)
    {   
        sum+=tong[i];
        if(sum>k)
        {
            ans=ans*ksm(i,k)%mod;
            break;
        }
        else
        {
            ans=ans*ksm(i,sum)%mod;
            k-=sum;
        }
    }
    if(sum<k)printf("-1");
    else printf("%lld\n",ans);
}
