#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

/*Soln idea
Sort a given input vector using 2 stacks and throw the sorted one and mention the steps
*/

int main() {
    fastio
    ll n; cin >> n;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll cur = 1;
    stack<ll> st1, st2; //for 2 dead-ends
    vector<bool> in1(n + 1), in2(n + 1); //for keeping track whether current permutation value present in stacks

    for (ll i = 0; i < n; i++) {
      //by default we insert elements in dead-end 1
        ll x = a[i];
        cout << "1\n";
        in1[x] = true;
        st1.push(x);
      //now we'll check whether the current value for permutation is present in any of the dead-ends
        while (in1[cur] || in2[cur]) {
         
         //cur is present in 1st dead-end
         if (in1[cur]) {
            //now as we know cur is present here but if it isn't the 
            //top value we'll send the top values to D2 untill we find the cur
             while (st1.top() != cur) {
                 cout << "12\n";
                 ll nxt = st1.top();
                 st1.pop();
                 in1[nxt] = false;
                 in2[nxt] = true;
                 st2.push(nxt);
             }
             //if top one is cur now, we'll send it to output & pop
             cout << "-1\n";
             st1.pop();
         } 
         //Now, we'll repeat the process for D1 with D2 (here cur is present in D2)
         else {
             while (st2.top() != cur) {
                 cout << "21\n";
                 ll nxt = st2.top();
                 st2.pop();
                 in2[nxt] = false;
                 in1[nxt] = true;
                 st1.push(nxt);
             }
             cout << "-2\n";
             st2.pop();
         }
         //after each successful op we'll increment current
         cur++;
        }
    }
    return 0;
}
