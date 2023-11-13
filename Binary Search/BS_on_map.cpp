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
   
  
#include <iostream>
#include <map>

template <typename Key, typename Value>
typename std::map<Key, Value>::const_iterator
map_binary_search(const std::map<Key, Value>& m, const Key& key) {
    // Binary search for key in map
    auto lower = m.begin();
    auto upper = m.end();
    while (lower != upper) {
        auto mid = std::next(lower, std::distance(lower, upper) / 2);
        if (mid->first == key) {
            return mid;
        } else if (mid->first < key) {
            lower = std::next(mid);
        } else {
            upper = mid;
        }
    }
    return m.end();
}
template <typename Key, typename Value>
typename map<Key, Value>::const_iterator
map_lower_bound(const std::map<Key, Value>& m, const Key& key) {
    // Binary search for key in map
    auto lower = m.begin();
    auto upper = m.end(); 
    while (lower != upper) {
        auto mid = next(lower, distance(lower, upper) / 2);
        if (mid->first >= key) {
            return mid;
        } else if (mid->first < key) {
            lower = next(mid);
        } else {
            upper = mid;
        }
    }
    return m.end();
}

template <typename Key, typename Value>
typename std::map<Key, Value>::const_iterator
map_upper_bound(const std::map<Key, Value>& m, const Key& key) {
    // Binary search for key in map
    auto lower = m.begin();
    auto upper = m.end();
    while (lower != upper) {
        auto mid = std::next(lower, std::distance(lower, upper) / 2);
        if (mid->first == key) {
            return mid;
        } else if (mid->first < key) {
            lower = std::next(mid);
        } else {
            upper = mid;
        }
    }
    return m.end();
}
int main() {
	fastio
    std::map<int, std::string> m {
        {1, "apple"},
        {2, "banana"},
        {4, "mango"},
        {4, "orange"},
        {5, "peach"},
        {6, "grape"}
    };

    // Binary search for key 4
    auto it = map_lower_bound(m, 4);
    if (it != m.end()) {
        std::cout << "Found: " << it->first << " " << it->second << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
