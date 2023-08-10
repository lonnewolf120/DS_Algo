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
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 

const ll N = 1e5+10;

vector<ll> v(N),v2(N);

int fib(int n)
{
//base case will be values of v[0] & v[1]
	if(v[n]!=0) return v[n]; //if already calculated, then return value
	v[n] = fib(n-1)+fib(n-2);	//calculate value
	return v[n];
}
int fact(int n)
{
//base case will be values of v2[0] & v2[1]
	if(v2[n]!=0) return v2[n];
	v2[n] = n*fact(n-1);
	return v2[n];
}
void solve()
{
	//base cases for fib
	v[0]=v[1]=1;
	fib(10);
	//base cases for factorial
	v2[0]=v2[1]=1;
	fact(10);
	cout << v[10] << ln << v2[3];
}

int main()
{
    fastio
    solve();
    return 0;
}