#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
string Arr[MAXN];
string Ans="GOOD SET\n";

struct node{
    node *Child[11];
    ll cnt,h;
    node(){
        cnt=0,h=0;
        for(ll i=0;i<11;i++){
            Child[i]=nullptr;
        }
    }
};

node *root;

void Add_string(string s){
    node *cur = root;
    for(ll i=0;i<s.length();i++){
        ll r=s[i]-'a';
        if(cur->Child[r]==nullptr){
           cur->Child[r]=new node();
        }
        cur=cur->Child[r];
        cur->cnt++;
        if(cur->cnt>1&&cur->h){
            if(Ans=="GOOD SET\n"){Ans="BAD SET\n"+s;}
        }
    }
    if(cur->cnt>1){
        if(Ans=="GOOD SET\n"){Ans="BAD SET\n"+s;}
    }
    cur->h=1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    root=new node();

    ll n;cin>>n;
    for(ll i=0;i<n;i++){cin>>Arr[i];}
    for(ll i=0;i<n;i++){Add_string(Arr[i]);}
    cout<<Ans<<"\n";

    return 0;
}
