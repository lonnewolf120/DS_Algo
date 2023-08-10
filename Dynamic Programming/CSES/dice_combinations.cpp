#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
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


int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<int> dp(n+1,0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6 && i-j >= 0; j++) {
      (dp[i] += dp[i-j]) %= mod;
    }
  }
  cout << dp[n] << endl;
}