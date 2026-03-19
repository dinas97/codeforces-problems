#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN],Brr[MAXN];
ll Tree[4*MAXN];

void Build(ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){Tree[id]=Arr[st];return;}
    ll mid=(st+en)/2;
    Build(st,mid,2*id);
    Build(mid+1,en,2*id+1);
    Tree[id]=Tree[2*id]+Tree[2*id+1];
}

ll Query(ll val,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){return st;}
    ll mid=(st+en)/2;
    if(Tree[2*id+1]<=val){
        return Query(val-Tree[2*id+1],st,mid,2*id);
    }
    else{
        return Query(val,mid+1,en,2*id+1);
    }
}

void Update(ll pos,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){Tree[id]=0;return;}
    ll mid=(st+en)/2;
    if(pos<=mid){
        Update(pos,st,mid,2*id);
    }
    else{Update(pos,mid+1,en,2*id+1);}
    Tree[id]=Tree[2*id]+Tree[2*id+1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n;cin>>n;
    for(ll i=1;i<=n;i++){Arr[i]=1;}
    Build();
    for(ll i=1;i<=n;i++){
        cin>>Brr[i];
    }
    vector<ll>Ans;
    for(ll i=n;i>=1;i--){
        ll p = Query(Brr[i]);
        Update(p);
        Ans.push_back(p);
    }
    reverse(Ans.begin(),Ans.end());
    for(auto r:Ans){cout<<r<<" ";}

    return 0;
}
