#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];
string t,p;

bool f(ll x){
    vector<ll>b; b.resize(t.size(),0);
    for(ll i=1;i<=x;i++){
        b[Arr[i]]++;
    }
    ll h=1;
    for(ll i=1,j=1;i<p.length();i++){
        h=0;
        for(;j<t.length();j++){

            if(p[i]==t[j]&&!b[j]){j++;h=1;break;}
        }
        if(!h){return 0;}
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    cin>>t>>p;
    t='#'+t;p='#'+p;
    for(ll i=1;i<t.length();i++){
        cin>>Arr[i];
    }
    ll Ans=0;
    ll l=0,r=t.length()-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(f(mid)){
            Ans=mid;
            l=mid+1;
        }
        else{r=mid-1;}
    }
    cout<<Ans<<"\n";

    return 0;
}

