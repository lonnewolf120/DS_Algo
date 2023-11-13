#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
   
typedef long long ll;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
   
  

int main()
{
    ll n, k1, k2;
    cin >> n >> k1;
    queue<ll> q1, q2;
    for (ll i = 0; i < k1; i++)
    {
    }
    ll card;
    cin >> card;
    q1.push(card);
    cin >> k2;
    for (ll i = 0; i < k2; i++)
    {
    }
    ll card;
    cin >> card;
    q2.push(card);
    ll fights = 0;
    while (!q1.empty() && !q2.empty() && fights < 1e5 + 9)
    {
        ll c1 q1.front();
        q1.pop();
        ll c2 = q2.front();
        q2.pop();
        if (c1 > c2)
        {
            q1.push(c2);
            q1.push(c1);
        }
        else
        {
            q2.push(c1);
            q2.push(c2);
        }
    }
    fights++;
    if (fights == 1e5 + 9)
    {
        cout << "-1\n";
    }
    else if (q1.empty())
    {
        cout < < < < fights < < <
            "2\n";
    }
    else
    {
        cout < < < < fights < < < 1\n ";
    }
    return 0;
}