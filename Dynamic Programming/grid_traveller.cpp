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
 const ll N = 100;
 ll grid[N][N];
 bool isVisited[N][N];

 int gridTravel(int i, int j)
 {
 	if(i==0 || j==0) return 0;
 	if(i==1 && j ==1) return 1;
 	//if(i>n) return 0;
   int val=0;
 	val += gridTravel(i,j-1);
 	val += gridTravel(i-1,j);
 	return val;
 }

 int gridTravel1(int i, int j)
 {
   if(i==0 || j==0) return 0;
   if(i==1 && j ==1) return 1;
   return gridTravel1(i,j-1) + gridTravel1(i-1,j);
 }

 ll gridTravel2(ll i, ll j)
 {
    if(grid[i][j]!=0) return grid[i][j];
    if(i==0 || j==0) return 0;
    if(i==1 && j ==1) return 1;
    grid[i][j]=gridTravel2(i,j-1)+gridTravel2(i-1,j);
    return grid[i][j];
 }
 int main()
 {
     fastio
     //int n; cin >> n;
    
     gridTravel2(20,20);
     cout << grid[18][18] << endl;
     return 0;
 }