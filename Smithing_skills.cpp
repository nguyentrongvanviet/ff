#include<bits/stdc++.h>
using namespace std ; 

const int N = 1e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

int n , m ; 
int cost[N] , melt[N] , ingot[N] ; 
int mi[N] ; 
int f[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    // freopen("text.INP","r",stdin) ; 
    // freopen("text.OUT","w",stdout) ; 
    cin>> n >> m; 
    for(int i=1;i<=n;i++)cin>>cost[i] ; 
    for(int i=1;i<=n;i++)cin>>melt[i] ; 
    for(int i=1;i<=m;i++)cin>>ingot[i] ; 
    for(int i=0;i<=1e6;i++)mi[i] = oo ; 
    for(int i=1;i<=n;i++)
    {
        mi[cost[i]] = min(mi[cost[i]],cost[i]-melt[i]) ; 
    }
    for(int i=1;i<=1e6;i++)mi[i]=min(mi[i],mi[i-1]) ; 
    for(int i=1;i<=1e6;i++)if(i>=mi[i])
    {
        f[i] = f[i-mi[i]]+2;
    }
    long long res = 0 ;
    int t = mi[(int)1e6] ; 
    for(int i=1;i<=m;i++)
    {
        if(ingot[i]<=1e6)res+=f[ingot[i]] ;
        else{
            int s =(ingot[i]-(int)1e6)/t+((ingot[i]-(int)1e6)%t!=0);
            res+=2*s+f[ingot[i]-s*t] ; 
        }
    }
    cout<<res<<'\n'; 
}