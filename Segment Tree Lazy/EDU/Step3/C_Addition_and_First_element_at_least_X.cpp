#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];

struct node{
    ll mr,add,mx;
    node(){mr=0,add=0,mx=0;}
};
node Tree[4*MAXN];

void shift(ll id){
    ll left=2*id,right=2*id+1;
    if(Tree[id].mr){
        Tree[left].mr=1,Tree[left].add+=Tree[id].add,Tree[left].mx+=Tree[id].add;
        Tree[right].mr=1,Tree[right].add+=Tree[id].add,Tree[right].mx+=Tree[id].add;
    }
    Tree[id].mr=0,Tree[id].add=0;
}

void Update(ll l,ll r,ll val,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id);
    if(en<l||st>r){return;}
    if(l<=st&&en<=r){
        Tree[id].mr=1,Tree[id].add+=val,Tree[id].mx+=val;
        return;
    }
    ll mid=(st+en)/2;
    Update(l,r,val,st,mid,2*id);
    Update(l,r,val,mid+1,en,2*id+1);
    Tree[id].mx=max(Tree[2*id].mx,Tree[2*id+1].mx);
}

ll Query(ll l,ll x,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id);
    if(en<l){return -1;}
    if(st==en){
        return st;
    }
    ll mid=(st+en)/2;
    if(Tree[2*id].mx>=x){
        ll c=Query(l,x,st,mid,2*id);
        if(c==-1 && Tree[2*id+1].mx>=x){return Query(l,x,mid+1,en,2*id+1);}
        else{return c;}
    }
    else if(Tree[2*id+1].mx>=x){
        return Query(l,x,mid+1,en,2*id+1);
    }
    else{return -1;}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    while(m--){
        ll t,l,r,v;
        cin>>t>>l>>r;
        if(t==1){
            cin>>v;
            r--;
            Update(l,r,v);
        }
        else{
            cout<<Query(r,l)<<"\n";
        }
    }

    return 0;
}

