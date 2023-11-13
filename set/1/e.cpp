#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
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

void solve() {
    int n;
    cin >> n;

    multiset<pair<int, int> > s;
    multiset<pair<int, int> >::iterator iter;

    s.clear();

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if ((iter = s.find(make_pair(b, a))) == s.end()) {
            s.insert(make_pair(a, b));
        } else {
            s.erase(iter);
        }
    }

    if (s.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fastio

    ll t;
    cin >> t;

    for(int it=1;it<=t;it++) {
        solve();
    }

    return 0;
}
