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

ll const N=10e3;
ll pre_calc[N];
ll wdcnt[30];
string s;
void solve(){
	ll n;
	cin>>n;
	cin>>s;
	for(ll i=0;i<N;i++)pre_calc[i]=1e9;
	memset(wdcnt,-1,sizeof(wdcnt));
	forn(i,n)
	{
		if(s[i]=='A'){
			wdcnt[0]=i;
			pre_calc[i]=1;
		}else {
			ll pre=wdcnt[s[i]-'A'-1];
			if(pre!=-1)
			if(pre_calc[pre]!=1e9){
				pre_calc[i]=i-pre+pre_calc[pre];
				wdcnt[s[i]-'A']=i;
			}
		}
	}
	ll ans=1e9;
	for(ll i=0;i<n;i++)
	if(s[i]=='Z')
	if(pre_calc[i]!=1e9)
	ans=min(ans,pre_calc[i]);
	cout<<ans<<ln;
}
int main(){
	freopen("collectingofficer.in","r",stdin);
	ll t; cin>>t;
	forn(i,t)
		solve();
     return 0;
}