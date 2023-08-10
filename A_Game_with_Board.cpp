#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool aliceWins = true;
    for (int i = 0; i < n; i++) {
      if (n % 2 == 1 && i == n - 1) {
        aliceWins = false;
        break;
      } else if (n % 2 == 0 && i == n - 2) {
        aliceWins = false;
        break;
      }
      if (i % 2 == 0) {
        if (n - i - 1 >= 2 && (n - i - 1) % 2 == 0) {
          aliceWins = false;
          break;
        }
      } else {
        if (n - i - 1 >= 1 && (n - i - 1) % 2 == 1) {
          aliceWins = false;
          break;
        }
      }
    }
    if (aliceWins) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  }
  return 0;
}
