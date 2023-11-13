#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5005;
vector<int> g[N];
int sz[N], val[N], pos[N];

bool compare(int a, int b) {
    return sz[a] < sz[b];
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        pos[i] = i;
    }

    dfs(1, 0);
    sort(pos + 1, pos + n + 1, compare);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += 1LL * (i - 1) * val[pos[i]] + 1;
    }

    cout << ans << endl;

    return 0;
}
