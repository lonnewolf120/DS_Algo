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

map<string, string> mp1,mp2;
set<string> input;

//unaccepted
   
void inp()
{
	string a,b; cin >> a >> b;
	input.insert(a); input.insert(b);
	mp1[a]=b;
	mp1[b]=a;
	//auto i = mp1.find(a), i2=mp2.find(b);
}
map<string, bool> visited;

vector<string> dfs(string vertex)
{
    vector<string> result;
    if (visited[vertex]) {
        return result;
    }
    visited[vertex] = true;
    result.push_back(vertex);
    for (string neighbor : mp1[vertex]) {
        if (!visited[neighbor]) {
            vector<string> sub_result = dfs(neighbor);
            result.insert(result.end(), sub_result.begin(), sub_result.end());
        }
    }
    return result;
}

int main()
{
    fastio
    ll t,c=0;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        inp();
    }
    for(auto i:input)
    {
      if(!visited[i]) dfs(i);
      ++c;
    }
    cout << c << ln;
    return 0;
}