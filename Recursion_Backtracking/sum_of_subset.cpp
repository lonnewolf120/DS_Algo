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

vector<int> v;
vector<vector<int>> ans;
int n;

//Issues fixed: if a tmp vector is not set as parameter, 
//it is not being updated (push,pop happens to empty vector every time if not taken as parameter)
void sumSub(int i, int targetSum, 
   vector<int> tmp={})
{
   if(i==n && targetSum==0)
   {
      ans.push_back(tmp);
      // return;
   }
   if(i==n) return;

   if(v[i]<=targetSum)
   {
      tmp.push_back(v[i]);
      sumSub(i+1, targetSum-v[i], tmp);
      tmp.pop_back();
   }
   sumSub(i+1, targetSum, tmp);

}
int main()
{
    fastio
    // ll t;
    cin>>n;
    v.resize(n,0);
    for (int i = 0; i < n; ++i)
       cin>>v[i];
    int t; cin>>t;
    sumSub(0,t);
    cout<<ans.size()<<ln;
    for (auto i:ans)
    {
      cout<<"{";
      for(auto j:i)
         cout<<j<<",";
       /* code */
      cout<<"}\n";
    }

    return 0;
}