#include <bits/stdc++.h>
using namespace std;

vector<int> resultArray(vector<int>& nums) {
  vector<int> res;
  int i = 0, c1 = 0;

  while (i < nums.size()) {
    res.push_back(nums[i]);
    if (i + 1 < nums.size()) {
      res.push_back(nums[i + 1]);
      i += 2;
    } else {
      i++;
    }
  }

  return res;
}

int main() {
  vector<int> v = {2, 1, 3};
  vector<int> res = resultArray(v);
  for (auto i : res) cout << i << " ";
  cout << endl;
  return 0;
}
