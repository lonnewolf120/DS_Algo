#include <iostream>

using namespace std;

bool canReach(int n, int m) {
    if (n > m) return false;  // can't end up with a larger pile than we started with

    if (n == m) return true;  // we already have the target size

    if (m % 2 == 1) return false;  // odd numbers can't be reached by splitting even numbers

    if (n * 2 <= m) return true;  // we can reach the target by doubling the pile

    // otherwise, we try to split the pile
    return canReach(n, m/2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (canReach(n, m)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
