    /*
______                                 _____________   _______   _________________           
___  /____________________      __________  /__  __/   ____  /   ___(_)__  __/_  /__________ 
__  /_  __ \_  __ \  _ \_ | /| / /  __ \_  /__  /_     ___  /    __  /__  /_ _  __/  _ \  _ \
_  / / /_/ /  / / /  __/_ |/ |/ // /_/ /  / _  __/     __  /     _  / _  __/ / /_ /  __/  __/
/_/  \____//_/ /_/\___/____/|__/ \____//_/  /_/        _  /      /_/  /_/    \__/ \___/\___/ 
                                                       /_/                                   
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n,ans=0; cin>>n;
    //calc factors of n
    for(ll i=1;i<=sqrt(n);i++) 
    {
        if(n%i==0) 
        {
            //cout<<i<<" " << n/i <<"\n";
            ans+=i+n/i;
        }
    }
    ll k=sqrt(n);
    if (k*k==n) ans-=k;
    cout<<ans<<"\n";
}
int main()
{
    fastio
    ll t; cin>>t;
    while (t--)
    {
        solve();
    }
}