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

   
vector<pair<int,int>> moves=
{
    {2,1}, {2,-1}, {-2,1},{-2,-1},
    {1,2}, {1, -2}, {-1, 2}, {-1, -2}
};
int vv[200][200];
void maxBoard(int i, int j, int n, int m)
{
    if(i<0 || j < 0) return;
    if(i > n || j > m) return;
    vv[i][j]=1;
    for(auto k:moves)
    {
        maxBoard(i+k.first,j+k.second,n,m);
    }
    //return 0;
}

int main()
{
    int t,n,m; cin >> t;
    while(t--)
    {
        cin >> n >> m;
        maxBoard(0,0,n,m);
        maxBoard(1,1,n,m);
    }
    for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cout << vv[i][j] << " ";
                
            }
            cout << "\n";
        }
    
    return 0;
}