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

/*DFS on tree
const int N = 1e3+10;
vector<int> tree[N];
void dfs1(int vertex, int parent)
{
   for(auto child:tree[vertex]) //go to each child subtree and run dfs again
   {
      if(child!=parent) dfs1(child,vertex);
   }
}
*/

bool cmp(pair<char,int> a, pair<char,int> b)
{
   return a.second > b.second;
}
   
map<char,int> mp;
map<int,char> mp1;
int main()
{
    fastio
    string s;int n=3;
    while(n--)
    {
    	cin >> s;
    	if(s[1]=='>') {mp[s[0]]+=2; mp[s[2]]++;}
    	else if(s[1]=='<') {mp[s[2]]+=2; mp[s[0]]++;}
    }
    bool f=true;
    for(auto i:mp)
    {
      mp1[i.second]=i.first;
    }
    if(mp['A']==mp['B'] || mp['A']==mp['C'] || mp['C']==mp['B']) f=false;

    if(f) for(auto i:mp1) cout << i.second;
    else cout << "Impossible\n";
    return 0;
}