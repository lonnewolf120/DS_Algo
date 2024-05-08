#include <iostream>
#include <vector>

using namespace std;

bool check_value(long long v, vector<long long>& a, int i, long long k) {
    long long modified_value = 0;
    for (int j = i; j < a.size(); ++j) {
        if (a[j] >= v) {
            break;
        }
        if (j == a.size() - 1 && a[j] < v) {
            return false;
        } else {
            modified_value += v - a[j];
        }
        v = v - 1;
    }
    return modified_value <= k;
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        t--;

        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long ans = a[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            long long low = a[i];
            long long high = 1e12;

            while (low <= high) {
                long long mid = low + (high - low) / 2;
                if (check_value(mid, a, i, k)) {
                    low = mid + 1;
                    ans = max(ans, mid);
                } else {
                    high = mid - 1;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
