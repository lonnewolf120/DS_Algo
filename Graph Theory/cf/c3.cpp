#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;

ll solve();

int main() {
  cout << solve() << endl;

  return 0;
}

ll solve() {
  ll n;
  cin >> n;

  string a;
  cin >> a;

  vector<ll> blk;
  for (ll i = 0; i < n; i++) {
    if (a[i] == '#') {
      blk.push_back(i);
    }
  }

  ll beginn = blk[0];
  ll endd = blk[blk.size() - 1];

  ll res = n;

  for (ll i = 0; i < blk.size(); i++) {
    ll count = i + 1;

    ll j = blk[i];
    while (j < n && a[j] == '#') {
      j++;
      count++;
    }

    ll cWhite = n - j + 1;

    res = min(res, count + cWhite);
  }

  return res;
}
