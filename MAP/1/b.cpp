#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main()
{
    fastio
    ll n, t;
    cin >> n >> t;
    unordered_map<string, pair<string, int>> mp;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        mp[a] = {b, 0};
    }
    unordered_map<string, int> mp2;
    for (int i = 0; i < t; i++)
    {
        string a;
        cin >> a;
        mp[a].second++;
        mp2[mp[a].first]++;
    }
    string country;
    ll m = INT_MIN;
    for (auto i : mp2)
    {
        if (i.second > m)
        {
            m = i.second;
            country = i.first;
        }
        else if (i.second == m)
        {
            if (i.first < country)
            {
                country = i.first;
            }
        }
    }
    cout << country << endl;
    m = INT_MIN;
    country = "";
    for (auto i : mp)
    {
        if (i.second.second > m)
        {
            m = i.second.second;
            country = i.first;
        }
        else if (i.second.second == m)
        {
            if (i.first < country)
            {
                country = i.first;
            }
        }
    }
    cout << country << endl;
}