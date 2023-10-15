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
   
  
class Solution {
public:
    bool ismatching(char a, char b)
    {
        if(a=='(' && b==')') return true;
        if(a=='[' && b==']') return true;
        if(a=='{' && b=='}') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s)
        {
            if(c=='(' || c=='[' || c=='{')stk.push(c);
            else if(!stk.empty())
            {
                if(ismatching(stk.top(),c)) stk.pop();
                else return false;
            } 
            else stk.push(c);
    
        }
        return stk.empty()?true:false;

    }
};
int main()
{
    fastio
    //ll t;
    //cin >> t;
    Solution solve;
    //for(int it=1;it<=t;it++) {
    //cout << "Case " << it << ": ";
	string s; cin >> s;
    (solve.isValid(s))?cout <<"true":cout <<"false";
    //}
    return 0;
}