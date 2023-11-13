#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

char input[200005];
int black_indices[200005];
int num_black_indices = 0;
int start_index = 0;
int end_index = 0;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> input[i];
    if (input[i] == '#') {
      black_indices[num_black_indices++] = i;
    }
  }

  int min_length = n;

  for (int i = 0; i < num_black_indices; i++) {
    int current_length = i + 1;
    int j = black_indices[i];
    while (j < n && input[j] == '#') {
      j++;
      current_length++;
    }
    int remaining_length = n - j;
    min_length = min(min_length, current_length + remaining_length);
  }

  cout << min_length << endl;

  return 0;
}
