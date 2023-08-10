#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define o_set tree<ll, null_type,greater<ll>, rb_tree_tag,tree_order_statistics_node_update>
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

void solve()
{
	ll n,ans=0; cin >> n;
	o_set st;
	forn(i,n)
	{
		ll a; cin >> a;
		ll big= st.order_of_key(a);
		ans+=a+big-(i+1);
		st.insert(a);
	}
	cout<<ans<<ln;

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