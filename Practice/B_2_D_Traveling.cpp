/*
______                                 _____________        
___  /____________________      __________  /__  __/   
__  /_  __ \_  __ \  _ \_ | /| / /  __ \_  /__  /_     
_  / / /_/ /  / / /  __/_ |/ |/ // /_/ /  / _  __/     
/_/  \____//_/ /_/\___/____/|__/ \____//_/  /_/        
                                                                                          
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

/* 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag, \ 
tree_order_statistics_node_update> indexed_set; // use less_equal for multiset 
// order_of_key (val): returns the no. of values less than val 
// find_by_order (k): returns the iterator to kth largest element.(0-based) 
*/

typedef long long ll;
typedef long double ld;
#define PQ(type) priority_queue<type> 
#define PQD(type) priority_queue<type,vector<type>,greater<type> > 

ll MOD = 998244353;
double eps = 1e-12;
#define FOR(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define eb emplace_back
#define INF 1<<30
#define LW ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define tst ll t; cin >> t; while(t--)
#define PI 3.1415926535897932384626433832795l 

// --------------------<DEBUG>--------------------------
template<typename T>
ostream& operator<<(ostream& os, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cout << a << ' '; return os; }
template<typename T>
istream& operator>>(istream& is, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cin >> a; return is; }
template<typename T>
void print(T a) { cout << a << endl; }
template<typename T, typename... Args>
void print(T a, Args... b) { cout << a << " "; print(b...); } 
template<typename T>
void _debug(T a) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << "]" << endl;
}
template<typename T, typename... Args>
void _debug(T a, Args... b) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << ",\t";
    _debug(b...);
}
template<typename... Args>
void debug(Args... b) { cout << '['; _debug(b...); }

// --------------------<DEBUG>--------------------------




// ----------------------<MATH>--------------------------- 
/*
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
int add(int a, int b, int c = MOD){int res=a+b;return(res>=c?res-c:res);} 
int mod_neg(int a, int b, int c = MOD){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);} 
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;return(res>=c?res%c:res);} 
int muln(int a, int b, int c = MOD){ll res=(ll)a*b;return ((res%c)+c)%c;} 
ll mulmod(ll a,ll b, ll m = MOD){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;} 
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;} 
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;} 
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\ 
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;} 
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));} 
  
const int FACSZ = 1; // Make sure to change this 
  
ll fact[FACSZ],ifact[FACSZ]; 
  
void precom(ll c = MOD){ 
    fact[0] = 1; 
    FOR(i,1,FACSZ) fact[i] = mul(fact[i-1],i,c); 
    ifact[FACSZ-1] = mod_inverse(fact[FACSZ-1],c); 
    REPD(i,FACSZ-1){ 
        ifact[i] = mul(i+1,ifact[i+1],c); 
    } 
} 
string dectobin(ll n)
{
    string s = bitset<64> (n).to_string();
    const auto loc1 = s.find('1');
    if(loc1 != string::npos)
        return s.substr(loc1);
    return "0";
}

ll ncr(ll n,ll r,ll c = MOD){ 
    return mul(mul(ifact[r],ifact[n-r],c),fact[n],c); 
}

ll powa(ll a, ll b, ll m = mod){
    if (b == 0)
        return 1ll;
    else if (b == 1)
        return a;
    else
    {
        ll x = powa(a, b/2, m);
        x *= x;
        // x %= m;
        if (b%2)
        {
            x *= a;
            // x %= m;
        }
        return x;
    }
}
*/
// ----------------------</MATH>-------------------------- 

// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

// ----------------------</BITWISE>-------------------------- 
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
// ----------------------</BITWISE END>-------------------------- 

/****************** Prime Generator **********************/ 
const int N=1e7+10; int prime[20000010]; 
bool isprime[N]; int nprime; 
template <typename T> void Sieve(T a) 
{nprime = 0;memset(isprime,true,sizeof(isprime));
isprime[1]=false;for(int i=2;i<N;i++){
if(isprime[i]){prime[nprime++]=i;for(int j=2;i*j<N;j++)
isprime[i*j]=false;}}}
/*
template <typename T> bool miller_rabin(T p, T itt) 
{if(p<2) return 0 ;if(p==2) return 1;if(p%2==0) 
return 0 ;ull s = p-1 ;while(s%2==0) s/=2;
for(ll i=1;i<=itt;i++) {ull a = rand() % (p-1)+1 , temp = s ;
ull mod = modulo(a,temp,(ull)p);while(mod!=1 and mod!=p-1 
and temp!=p-1){mod = Mulmod(mod,mod,(ull)p);temp*=2;}
if(temp%2==0 and mod!=p-1) return false ;}return true;} 
*/
template <typename T> inline T PrimeFactors(T n)
{ll cnt=0,sum=1;for(int i=0; prime[i]*prime[i]<=n 
and i<nprime;i++){cnt=0;while(n%prime[i]==0)
{cnt++;n/=prime[i];}sum*=(cnt+1);}
if(n>1)sum*=2;return sum;} 

/****************** Prime Generator End **********************/ 


#define yes cout<<"YES\n"
#define no cout<<"NO\n"
//rep(i,1,10) for loop 1 to 10 and rep(i,10,1) for loop 10 to 1 
//also works for iterators: rep(it, end(v), begin(v))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll inf = 4e9+1;
//#define revSort(&v) sort(begin(v), end(v), [] (int a, int b) { return a > b; });
void solve()
{
    ll n,k,a,b; cin>>n>>k>>a>>b; a--;b--;
    vector<pair<ll,ll>> v(n);
    rep(i,0,n) cin>>v[i].first>>v[i].second;
    ll ans=abs(v[a].first-v[b].first)+abs(v[a].second-v[b].second);
    ll m1 = inf, m2=inf;
    rep(i,0,k)
    {
        m1=min(m1,abs(v[a].first-v[i].first)+abs(v[a].second-v[i].second));
        m2=min(m2,abs(v[b].first-v[i].first)+abs(v[b].second-v[i].second));
    }
    ans=min(ans,m1+m2);
    cout<<ans<<ln;
}
int32_t main()
{
    LW;
    tst
    {
        solve();
    // ll n; cin>>n; vector<ll> v(n); for(auto &i:v) cin>>i;
    }
    return 0;
}