#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
// #define map unordered_map

string ans;

void dfs(char src,
map<char,set<char>> &g,
map<char,bool> &visited)
{
   // bool f= true;
   visited[src]=true;
   ans+=(src);
   for(auto i:g[src])
   {
      if(!visited[i])
      {
         // if(!dfs(i,g,visited,par))return false;
         dfs(i,g,visited);
         // par[i]=src;
      }
      // else if(par[src]!=i)
         // f= false;
   }
   // return f;
}
void solve()
{
   string a; cin >> a;
   map<char,set<char>>g;
   set<char> nodes;
   map<char,bool> visited;
   // map<char,char> par;
   ll n=a.size(),cnt=0;char start;
   bool f=true;
   forn(i,n-1)
   {
      nodes.insert(a[i]);
      nodes.insert(a[i+1]);

      g[a[i]].insert(a[i+1]);
      g[a[i+1]].insert(a[i]);

   }
   start=a[0]; 
   for(auto i:nodes)
   {
      if(g[i].size()>2) {f=false;break;}
      else if(g[i].size()==1)
      {
         ++cnt;
         start=i; 
      }
   }
   if(cnt!=2)f=false;
   // bool f;
   // dfs(a[0],g,visited,par);
   // visited.clear();
   ans="";
   // dbg(g);
   if(a.size()==1)
   {
      yes;
      cout<<a[0]<<ln;
      for(char i='a';i<='z';++i)
      {
         if(i!=a[0])cout<<i;
      }
      cout<<ln;
   }
   else if(f)
   {
      yes;
      dfs(start,g,visited);
      for(char i='a';i<='z';++i)
      {
         //traversing from the leafs first
         if(!visited[i])
            ans+=i;
      }
      cout<<ans<<ln;
      ans.clear();
   }
   else no;
}
int main()
{
    fastio
    ll t;//if
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}