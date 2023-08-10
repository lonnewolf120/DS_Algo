#include <bits/stdc++.h>
#include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
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


void build_tree(vector<ll>&tree,vector<ll>&arr, ll i, ll j, ll ind)
{
	if(i==j) {tree[ind]=arr[i];return;}
	ll mid=i+(j-i)/2;
	build_tree(tree,arr,i,mid-1,2*ind);
	build_tree(tree,arr,mid,j,2*ind+1);
	tree[ind]=tree[2*ind]+tree[2*ind+1];
}

ll query(vector<ll>& tree,ll ind, ll tLow,ll tHigh, ll rLow, ll rHigh){
/*
Queries will depend on the operation we need to perform, will be same for +,*, lil modification needed for max/min
max/min:
for given a query to find max in range(low,high) & every subtree's covered range (l,r)
now, there will occur 3 cases for subtree ranges: */

//(i) completely lies in range:
	if(tLow>=rLow && tHigh<=rHigh) return tree[ind];

//(ii) doesn't contain, then return INT_MIN
	if(tLow>rLow || tHigh<rHigh) return INT_MIN;

//(ii) overlap, return the max from both side op by declaring a mid, & recursively go to every portion & set left,right equals to query of left,right & return their max/min
	ll mid=tLow+(tHigh-tLow)/2;
	ll left=query(tree,2*ind,tLow,mid,rLow,rHigh);
	ll right=query(tree,2*ind+1,mid+1,tHigh,rLow,rHigh);
	return max(left,right);
}
int main()
{
    fastio
    ll t;
    cin >> t;
    vector<ll> arr(t);
    vector<ll> tree;
    for(auto &i:arr)cin>>i;
    build_tree(tree,arr,0,t-1,0);
	ll q;
	cin >> q;
	while(q)
	{
		ll l,r; cin >> l >> r;
		cout << query(tree,0,0,t-1,l,r) << ln;
	}
    return 0;
}