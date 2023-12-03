#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <C:\D Drive\Projects\debug2.h>
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
const int N = 10e3;
bool mark[N][N];
int n;

//Issues faced: if row wise traversal is not done at first,
//then we were getting infinite loop
bool isValid(int row, int col)
{

   for (int i = row, j=col; i > 0; i--)
      if(mark[i][j]) return false;
   for (int i = row, j=col; i > 0 && j>0; i--,j--)
      if(mark[i][j]) return false;
   for (int i = row, j=col; i > 0 && j<=n; i--, j++)
      if(mark[i][j]) return false;

   return true;
}
void printway()
{
   for (int i = 1; i <= n; ++i)
   {
      for (int j = 1; j <= n; ++j)
      {
         if(mark[i][j])cout<<"Q";
         else cout<<".";
         /* code */
      }
      cout<<ln;
      /* code */
   }
   for (int i = 1; i <= n; i++)
        cout << "-";
    cout << endl;

}
int cnt = 0;
void findway(int row)
{
   if(row==n+1)
   {
      ++cnt; printway(); return;
   }
   for (int i = 1; i <= n; ++i)
   {
      if(isValid(row,i))
      {
         mark[row][i]=true;
         findway(row+1);
         mark[row][i]=false;
      }

   }
}

void solve()
{
   // memset(mark, 0, sizeof(mark)); cnt=0;
   cin>>n;
   findway(1);
   cout<<cnt<<ln;
}
int main()
{
    fastio
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();

    }
    return 0;
}