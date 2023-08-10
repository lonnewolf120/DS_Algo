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


map<int,int>::const_iterator map_lower_bound(const map<int, int>& m, const int& key) {

    map<int,int>::const_iterator lower = m.begin(), upper = m.end(), mid; 

    while (lower != upper) {
        mid = next(lower, distance(lower, upper) / 2);
        if (mid->first == key) return mid;
        else if (mid->first < key)   //we'll only compare key, as values are frequencies
            lower = next(mid);
        else 
            upper = mid;
    }
    return upper;
}


int main() {
    fastio
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        int n, q;
        scanf("%d %d", &n, &q);
        map<int, int> freq_map;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            freq_map[a]++;
            freq_map[b+1]--;  // we increment at a and decrement at b+1 to mark the end of the range
        }
    /*input:
        6 12
        8 8
        10 12
        8 11
        0 12
        for cumulative frequency->
        index: 0 1 2 3 4 5 6 7 8 9 10 11 12

        value: 1 1 1 1 1 1 2 2 3 3 4  4  4
    */
        int cur_sum = 0;
        for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
            cur_sum += it->second;
            it->second = cur_sum;  // replace frequency with cumulative frequency
        }

        printf("Case %d:\n", k);
        for (int i = 0; i < q; i++) {
            int mark;
            scanf("%d", &mark);
            auto it = map_lower_bound(freq_map,mark);  // find the first key in the map greater than or equal to mark
            if (it != freq_map.end() && it->first == mark) {
                printf("%d\n", it->second);
            } else if (it == freq_map.begin()) {
                printf("0\n");
            } else {
                it--;  // move the iterator back one position
                printf("%d\n", it->second);
            }
        }
    }
    return 0;
}

