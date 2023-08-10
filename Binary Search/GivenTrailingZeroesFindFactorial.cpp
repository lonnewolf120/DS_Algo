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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

/* > Query: 
Find the x for whose factorial generates N trailing zeroes.. Here N will be given*/

/* > formula:
no of trailing zeroes in a factorial = powers of 2s and 5s in common,
but as 5s are less so, we consider powers of 5..
power of k in n = floor(n/k)+floor(n/k^2)+floor(n/k^3)+.. */

//Here this function calculates the no of trailing zeroes
//the factorial of n has using the above formula

/* > Concept:
Suppose we want to find the number of trailing zeroes in 100! We need to count the number of 5's 
in the prime factorization of numbers from 1 to 100, since there will always be more 2's than 5's. 
We can see that there are 20 numbers between 1 and 100 that have 5 as a factor 
(5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100). Among these, 
there are 4 numbers that have 5^2 as a factor (25, 50, 75, 100). So, the total number of 5's in 
the prime factorization of 100! is 20 + 4 = 24, which means that 100! has 24 trailing zeroes.
*/
int findZero(ll n)
{
   ll c=0,i=5;
   while(n/i>0)
   {
      c+=n/i;
      i*=5;
   }
   return c;
}
//Now we apply binary search to find the first no whose factorial has n trailing zeroes
/*
We can set a range for N from 0 to 5*M and then check the number of trailing zeroes in the 
prime factorization of N! using the above method. If the number of trailing zeroes is greater than 
or equal to M, we can move to the left half of the range to find a smaller value of N. 
Otherwise, we can move to the right half of the range to find a larger value of N. We can continue
 this until we find the minimum value of N that has M trailing zeroes
*/
int findNumber(ll n)
{
   ll l=0,h=5*n,mid,z;
   while(l<=h)
   {
      mid = l + (h-l)/2;
      //if(mid == n) {cout << mid << ln;break;}
      if(findZero(mid) < n) l = mid+1;
      else h = mid-1;
   }
   if(findZero(l)==n) return l;
   else return -1; 
}
void solve()
{
   ll n; cin >> n;
   ll m = findNumber(n);
   //cout << l << ln;
   (m==-1)?cout << "impossible\n": cout << m << "\n";
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}