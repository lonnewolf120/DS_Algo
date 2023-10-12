#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,y; cin>>n;
    map<string,ll> mp;
    string st;
    while(n--)
    {
        ll x;
        cin>>x;
        if(x==0) 
        {
            cin>>st;
            cin>>y;
            mp[st]=y;
        }
        else if(x==1)
        {
            cin>>st;
            cout<<mp[st]<<endl;
        }
        else if(x==2)
        {
            cin>>st;
            mp.erase(st);
        }
        else 
        {
            string a,b;
            cin>>a>>b;
            map<string,ll>::iterator i,ilw,iup;
            ilw = mp.lower_bound(a);
            iup= mp.upper_bound(b);
            for(i=ilw; i!=iup; ++i)
            {
                if(i->second!=0)cout<<i->first<<" "<<i->second<<"\n";
            }
        }
    }
}