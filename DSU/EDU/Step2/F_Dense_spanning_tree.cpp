#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Par[MAXN],Size[MAXN];

struct node{
    ll u,v,w;
    node(){u=0,v=0,w=0;}
};

bool comp(node a,node b){
    return a.w<b.w;
}

node Arr[MAXN];

ll Get_root(ll x){
    if(Par[x]==x){return x;}
    return Par[x]=Get_root(Par[x]);
}

void Union_set(ll u,ll v){
    u=Get_root(u),v=Get_root(v);
    if(Size[v]>Size[u]){swap(u,v);}
    Par[v]=u;Size[u]+=Size[v];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    for(ll i=1;i<=m;i++){
        cin>>Arr[i].u>>Arr[i].v>>Arr[i].w;
    }
    sort(Arr+1,Arr+m+1,comp);

    ll mn,mx,Ans=1e18,cnt=0;
    for(ll i=1;i<=m;i++){
        for(ll c=1;c<=n;c++){Par[c]=c,Size[c]=1;}
        cnt=0;
        if(Get_root(Arr[i].v)!=Get_root(Arr[i].u)){cnt++;}
        Union_set(Arr[i].v,Arr[i].u);
        mn=Arr[i].w;
        for(ll j=i+1;j<=m;j++){
            if(Get_root(Arr[j].v)!=Get_root(Arr[j].u)){cnt++;mx=Arr[j].w;}
            Union_set(Arr[j].v,Arr[j].u);
        }
        if(cnt==n-1){Ans=min(Ans,mx-mn);}
    }
    if(Ans==1e18){cout<<"NO\n";}
    else{cout<<"YES\n"<<Ans<<"\n";}

    return 0;
}

