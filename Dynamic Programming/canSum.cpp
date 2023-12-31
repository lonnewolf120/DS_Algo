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

//Can we make a sum arranging multiples of some array members
//to be equal to the target sum
const int N=1e3;
vector<int> pre(N);
bool canSum(int target, vector<int> arr)
{
   if(pre[target]!=0) return true;
	if(target==0) return true;
	if(target<0) return false;
	for(auto i:arr)
	{
		if(canSum(target-i,arr))
         {
            pre[target]=true;
            return true;
         }
	}
	return false;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
    	int a; cin >> a;
      int b; cin >> b;
    	vector<int> arr(a);
    	forn(i,a) cin >> arr[i];
      canSum(b,arr)? cout<<"true\n":cout<<"false\n";
    }
    return 0;
}