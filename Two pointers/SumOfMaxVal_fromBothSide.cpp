#include <bits/stdc++.h>
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

/*
Problem: http://codeforces.com/contest/381/problem/A
Intuition: Given an array, calc max values comparing both sides only & store them alternately in 2 variables

Solution:
Very easy problem but misunderstood and complicated the code. 
We can solve it with two pointer apporoach, 
where we'll store i=0,j=n-1 & compare v[i] & v[j], store the max alternately in 2 var 
& if v[i] is max do ++i, if v[j] then --j, and continue doing so until i<=j, 
then print the 2 vars
*/

void solve()
{
	ll n,a=0,b=0; cin>> n; vector<ll> v(n);
	for(auto &i:v)cin>>i;
	bool f=0;
	ll i=0,j=n-1,mx;
	while(i<=j)
	{
	if(v[i]>v[j])
	{
		mx=v[i];
		++i;
	}
	else
	{
		mx=v[j];
		--j;
	}
		f?a+=mx:b+=mx;
		f=!f;	
	}
	cout<< b << " " << a << ln;
}
int main()
{
    fastio
    solve();
    return 0;
}