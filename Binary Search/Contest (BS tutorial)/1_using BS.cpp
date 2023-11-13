//Contest Link: https://vjudge.net/contest/545084#overview

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
   
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

// int bs(ll n, vector<int> pre)
// {

// }
  
int first(vector<int> &pre, int h, int target)
{
	int l = 0;
	while(l<=h)
	{
		int mid = l+(h-l)/2;
		if(target == pre[mid]) return mid;
		else if(target>pre[mid]) l = mid+1;
		else h=mid-1;
	}
	return l;
}
void solve(){
	ll n,x; vector<int> v;
	vector<int> pre;
	ll q; vector<int> qu;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x; v.pb(x);
		if(i>0)pre.pb(pre[i-1]+x);
		else pre.pb(x);
	}
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> x;
		cout << first(pre,n,x)+1 << "\n";
	}
}
int main()
{
    fastio
        solve();
    return 0;
}