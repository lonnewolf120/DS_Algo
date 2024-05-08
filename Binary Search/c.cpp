#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll lower(vector<ll>& nums, ll target){
    ll l = 0, r = nums.size()-1, m = 0;
    while(l != r) {
        m = l+(r-l)/2;
        //if(nums[m]==target) return m;
        if(nums[m] >= target)
            r = m;
        else 
            l = m+1;
    }
    if(l<nums.size() && nums[l]<target)
    	l++;
    return l;
}
ll upper(vector<ll>& nums, ll target){
    ll l = 0, r = nums.size(), m = 0;
    while(l < r) {
        m = l+(r-l)/2;
        // if(nums[m]<=target) return m;
        if(nums[m] <= target)
            l = m+1;
        else 
            r = m;
    }
    if(l<nums.size() && nums[l]<=target)
    	l++;
    return r;
}
void solve()
{
	vector<ll> v;
	ll n,q,x,a,b,i,c=0; cin >> n >> q;
	while(n--) {cin >> x; v.push_back(x);}
	//v.resize(n);
	while(q--)
	{
		cin >> a >> b;
		auto l = lower(v,a);
		auto h = upper(v,b);
		//cout << h-l << "\n";
		cout << h-l << ln;
	}
	// while(q--)
	// {
	// 	cin >> a >> b;
	// 	ll l=0,h=n-1;
	// 	while(l<=h) 
	// 	{
	// 	int mid = l+ (h-l)/2;		//mid has to be put here because mid is being calculated everytime
	// 	if(v[mid]>= a && v[mid] <= b) ++c;
	// 	else if(v[mid])
	// 		{l=mid+1;}
	// 	else if(b<v[mid])
	// 		{++c;h=mid-1;}
	// 	}
	// }
	// cout << c << "\n";
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
    	cout << "Case " << it << ":\n";
        solve();
    }
    return 0;
}