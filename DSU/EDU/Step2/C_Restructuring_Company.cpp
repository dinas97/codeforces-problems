#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];
ll Par[MAXN],Next[MAXN],Size[MAXN];


ll Get_root(ll x){
    if(x==Par[x]){return x;}
    return Par[x]=Get_root(Par[x]);
}

void Union_set(ll x,ll y){
    x=Get_root(x);
    y=Get_root(y);
    if(x==y){return;}
    if(Size[x]>Size[y]){
        swap(x,y);
    }
    Par[x]=y;
    Size[y]+=Size[x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,q;cin>>n>>q;
    for(ll i=1;i<=n;i++){
        Par[i]=i;Next[i]=i+1;
        Size[i]=1;
    }
    while(q--){
        ll t,x,y;
        cin>>t>>x>>y;
        if(t==1){
            Union_set(x,y);
        }
        else if(t==2){
            for(ll i=x,nxt;i<y;i=nxt){
                Union_set(i,y);
                nxt=Next[i];
                Next[i]=Next[y];
            }
        }
        else{
            if(Get_root(x)==Get_root(y)){cout<<"YES\n";}
            else{cout<<"NO\n";}
        }
    }

    return 0;
}
