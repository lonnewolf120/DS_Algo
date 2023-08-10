	/*
______                                 _____________   _______   _________________           
___  /____________________      __________  /__  __/   ____  /   ___(_)__  __/_  /__________ 
__  /_  __ \_  __ \  _ \_ | /| / /  __ \_  /__  /_     ___  /    __  /__  /_ _  __/  _ \  _ \
_  / / /_/ /  / / /  __/_ |/ |/ // /_/ /  / _  __/     __  /     _  / _  __/ / /_ /  __/  __/
/_/  \____//_/ /_/\___/____/|__/ \____//_/  /_/        _  /      /_/  /_/    \__/ \___/\___/ 
                                                       /_/                                   
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
#define fc ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool chk(ll dst, ll n, ll c, vector<ll>& arr)
{
	ll last=arr[0],cnt=1;
	for (int i = 1; i <n; ++i)
	{
		if(arr[i]-last >= dst)
		{
			last = arr[i];
			++cnt;
		}
	}
	return (cnt>=c)?true:false;
}

void bin()
{
	ll n,c;
	cin >> n >> c;
	vector<ll> arr(n);
	for(auto &i:arr) cin >> i;
	sort(all(arr));
	ll l=0,r=arr[n-1]-arr[0];
	while(l<=r)
	{
		ll mid=l+(r-l)/2;
		if(chk(mid,n,c,arr)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<"\n";
}
int main()
{
    fc
    ll t; cin >> t;
    while(t--) {
        bin();
    }
    return 0;
}