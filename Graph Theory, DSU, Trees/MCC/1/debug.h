#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
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
#define yes cout << "YES\n"
#define no cout << "NO\n"
#ifdef ON_PC
    #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug.h> // replace with your path
#else
  #define deb(x...)
#endif
void dbg(int x) {cout << x << " ";}
void dbg(long x) {cout << x << " ";}
void dbg(long long x) {cout << x << " ";}
void dbg(unsigned x) {cout << x << " ";}
void dbg(unsigned long x) {cout << x << " ";}
void dbg(unsigned long long x) {cout << x << " ";}
void dbg(float x) {cout << x << " ";}
void dbg(double x) {cout << x << " ";}
void dbg(long double x) {cout << x << " ";}
void dbg(char x) {cout << '\'' << x << '\'';}
void dbg(const char *x) {cout << '\"' << x << '\"';}
void dbg(const string &x) {cout << '\"' << x << '\"';}
void dbg(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void dbg(const pair<T, V> &x) {cout << '{'; dbg(x.first); cout << ','; dbg(x.second); cout << '}';}
template<typename T>
void dbg(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), dbg(i); cout << "}";}
void _print() {cout << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {dbg(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << #x << " = ["; _print(x)
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}