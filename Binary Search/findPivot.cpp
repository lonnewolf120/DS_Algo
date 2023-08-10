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
   
  
int findPivot(vector<int> &v)
{
	int l = 0, h = v.size()-1,mid, pivot;
	while(l<=h)
	{
		mid = l+(h-l)/2;
		//when pivot is around mid
		if(mid>l && v[mid]<v[mid-1]) return v[mid-1];
		else if(mid<h && v[mid]>v[mid+1]) return v[mid];

		//other cases (pivot lies in unsorted region)
		else if(v[mid]>=v[h]) l=mid+1; //this means right part is unsorted
		else if(v[mid]<=v[l]) h=mid-1;
	}
	return v[pivot];
}
int main()
{
    fastio
    int n,x; cin >> n;
    vector<int> v;
    forn(i,n){cin >> x; v.pb(x);}
    
    cout << findPivot(v);
    return 0;
}