#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
#define ordered_set tree<int, null_type, less< int >, rb_tree_tag , tree_order_statistics_node_update>
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i <= e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

ordered_set st;
void solve()
{
	char n; cin >> n;
	int x; cin >> x;
	if(n=='I')
	{
		st.insert(x);
	}
	else if(n=='C')
	{
		cout << (st.order_of_key(x)) << ln;
	}
	else if(n=='K')
	{
		ll a= *(st.find_by_order(x-1));
		if(x <= st.size())
			cout<<a<<ln;
		else
			cout<<"invalid\n";
	}
	else if(n=='D')
	{
		if (st.find(x) != st.end())
     	st.erase(x);
	}
	
}
int main()
{
    // fastio
    int t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}