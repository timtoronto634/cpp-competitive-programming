#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

// count of each number
// array

int main() {
  int n;
  cin >> n;
  vector<ll> v(n, 0);
  for (int i=0;i<n;i++) {
    cin >> v[i];
  }
  map<int, int> cnt;
  for (int i=0;i<n;i++) {
    int found = cnt.count(v[i]);
    if (found == 0) {
      cnt.insert(make_pair(v[i], 1));
    } else {
      cnt[v[i]] = cnt[v[i]] + 1;
      // cout << cnt[v[i]] << " here" << endl;
    }
    // cout << cnt[v[i]] << endl;
  }
  int rest = cnt.size();
  vector<int> out(n+1, 0);
  map<int, int> num2numlarger;
  int idx = 1;
  for (auto x : cnt) {
    rest--;
    num2numlarger.insert(make_pair(x.first, rest));
  }
  map<int, int> numkind2numnums;
  for (auto y: num2numlarger) {
    numkind2numnums.insert(make_pair(y.second, cnt[y.first]));
    // cout << y.second << ":" << y.first << ":" << cnt[y.first] << endl;
  }

  for (int i=0;i<n;i++) {
    int kkk = numkind2numnums.count(i);
    if (kkk == 0) {
      cout << 0 << endl;
    } else {
      cout << numkind2numnums[i] << endl;
    }
  }

  return 0;
}
