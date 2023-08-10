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



void bfs(string sx,map<string, vector<string>> &g,map<string,bool> &visited,map<string,ll> &level, map<string,string> &par)
{
	visited[sx]=true;
	queue<string> q;
	q.push(sx);
	level[sx]=0;
	par[sx]="";

	while(!q.empty())
	{
		string p = q.front();
		q.pop();
		//visited[p]=1;
		for(auto i:g[p])
		{
			if(!visited[i])
			{
				visited[i]=true;
				level[i]=level[p]+1;
				par[i]=p;
				q.push(i);
			}
		}
	}
}
void printPar(string a, map<string,string> &par)
{
	if(par[a]=="") return;
	
	printPar(par[a],par);
	cout<<par[a]<<" "<<a<<ln;
}
void solve()
{
	bool f=false;	
	ll n; //cin>>n;
	while(cin >> n)
	{
		if(f)cout<<ln;
		f=true;
		map<string, vector<string>> g;
		map<string, string> par;
		map<string, bool> visited;
		map<string, ll> level;
		while(n--)
		{
			string u,v; cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		string a,b; cin >> a >> b;
		bfs(a,g,visited,level,par);
		//for(auto i:par)cout<<i.first<<" "<<i.second<<ln;
		//cout<<ln;
		if(!visited[b]) cout<<"No route\n";
		else printPar(b,par);
		//cout<<ln;
	}
}


	
int main()
{
    //fastio
    solve();
    return 0;
}