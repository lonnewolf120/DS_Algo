#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
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
#define yes cout << "Yes\n"
#define no cout << "No\n"

bool f;

void dfs(string src,
map<string,vector<string>> &g,
map<string,ll> &visited,
map<string,string> &par)
{
    visited[src]=1;
    for(auto i:g[src])
    {
        if(!visited[i])
        {
            dfs(i,g,visited,par);
            par[i]=src;
            //level[i]=level[src]+1;
        }
        if(visited[i]==1 && i!=par[src])
        {
            f=false;
            return;
        }
    }
    visited[src]=2;
}

  
bool solve()
{
    ll n; cin >> n;
    map<string,vector<string>> g;
    map<string,ll> visited;
    while(n--)
    {
        string a,b; cin >> a >> b;
        g[a].pb(b);
        visited[a]=visited[b]=0;
    }
    map<string,string> par;
    f=true;
    for(auto node:visited)
    {
        if(!visited[node.fi]) dfs(node.fi,g,visited,par);
        if(!f)return f;
    }
    return f;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     cout << "Case " << it << ": ";
        solve()?yes:no;
    }
    return 0;
}