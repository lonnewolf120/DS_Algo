#include <bits/stdc++.h>  
#include <math.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
ld eps = 1e-12;
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define FLOAT(x) setprecision(12)
 

// 1/y1 + 1/x1 = 1/c
// c = (x1*y1)/(x1+y1)

// (x1)^2 = x^2 + d^2
// (y1)^2 = y^2 + d^2

ld solve()
{
	ld x,y,c,m,n,a,val,mid;
	cin >> x >> y >> c;
	ld l=0.0, h=max(x,y);
	
	while(h-l >= eps)
	{
		mid = l + (h-l)/2.0;
		m = sqrt((x*x)-(mid*mid)); //m=x1
		a = sqrt((y*y)-(mid*mid)); //a=y1
		val = (a*m)/(a+m);
		if(val > c) l = mid;
		else h = mid;
	}
	return mid; //mid == c
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     	cout << "Case " << it << ": ";
     	ld v = solve(); cout << FLOAT(9) << v << ln;
    }
    return 0;
}