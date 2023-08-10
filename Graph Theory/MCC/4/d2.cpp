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
#define yes cout << "YES\n"
#define no cout << "NO\n"

int ans=0;
map<int, vector<int>> g;
vector<bool> visited;
map<pair<int,int>, int> dir;
map<pair<int,int>, int> wt;
   
void dfs(int node, int parent) 
{
    for(auto i : g[node]) {
        if(!visited[i] && i != parent) {
            visited[i] = true;
            ans+=dir[{i, node}] * wt[{i, node}];
            dfs(i, node);
        }
    }
}

int main()
{
    map<pair<ll,ll>,ll> wt;
    map<ll,bool> visited;
    map<ll,ll> dis;

    ll n,src=1,mx=-1; 
    cin >> n;
    forn(i,n)
    {
        ll u,v,w; cin >> u >> v >> w;
        g[u].pb(v);
        g[v].pb(u);
        wt[{v,u}]=w;  
        dir[{v,u}]=1; //0 for {u,v} so multiplying it will make wt 0        
    }
}