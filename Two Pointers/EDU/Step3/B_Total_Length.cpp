#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,s;cin>>n>>s;
    for(ll i=1;i<=n;i++){cin>>Arr[i];}
    ll sum=0,Ans=0;
    for(ll i=1,j=1;j<=n;j++){
        sum+=Arr[j];
        while(sum>s&&i<=j){
            sum-=Arr[i];
            i++;
        }
        if(sum<=s){
            ll x=j-i+1;
            Ans+=x*(x+1)/2;
        }
    }
    cout<<Ans<<"\n";

    return 0;
}

