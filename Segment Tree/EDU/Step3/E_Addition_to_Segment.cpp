#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN],Tree[4*MAXN];

void Update(ll l,ll r,ll val,ll st=0,ll en=MAXN-1,ll id=1){
    if(en<l||st>r){return;}
    if(l<=st&&en<=r){Tree[id]+=val;return;}
    ll mid=(st+en)/2;
    Update(l,r,val,st,mid,2*id);
    Update(l,r,val,mid+1,en,2*id+1);
}

ll Query(ll pos,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){return Tree[id];}
    ll mid=(st+en)/2;
    if(pos<=mid){return Tree[id]+Query(pos,st,mid,2*id);}
    else {return Tree[id]+Query(pos,mid+1,en,2*id+1);}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    while(m--){
        ll t,l,r,v;
        cin>>t>>l;
        if(t==1){
            cin>>r>>v;
            r--;
            Update(l,r,v);
        }
        else{
            cout<<Query(l)<<"\n";
        }
    }

    return 0;
}

