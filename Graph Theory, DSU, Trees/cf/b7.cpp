#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int k = n - 1;
        while (k > 0) {
            bool sorted = true;
            for (int i = 0; i < n - k; i++) {
                if (p[i] > p[i + k]) {
                    swap(p[i], p[i + k]);
                    sorted = false;
                }
            }
            if (sorted) {
                break;
            }
            k--;
        }
        cout << k + 1 << endl;
    }
    return 0;
}
