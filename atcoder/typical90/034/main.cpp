#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, k, ai;
  cin >> n >> k;
  vector<int> v;
  for (int i=0;i<n;i++) {
    cin >> ai;
    v.push_back(ai);
  }
  int left=0;
  int right=0;
  int kind=0;
  int maxrange = 0;
  unordered_map<int, int> cnts;

  while (left <= right && right < n) {
    while (kind <= k && right < n) {
      int nexnum = v[right];
      if (kind == k && cnts[nexnum] == 0) {
        // if nexnum is added, the kind is over k
        break;
      }
      if (cnts[nexnum] == 0) kind++;
      cnts[nexnum]++;
      right++;
      maxrange = max(right - left, maxrange);
    }

    while (kind == k && left <= right) {
      int leftnum = v[left];
      cnts[leftnum]--;
      if (cnts[leftnum] == 0) kind--;
      left++;
    }
  }
  cout << maxrange << endl;
  return 0;
}
