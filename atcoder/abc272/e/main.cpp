#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  vector<vector<ll>> level(m);
  for (ll mm=1; mm<=m;mm++) {
    for (ll aidx; aidx < a.size(); aidx) {
      ll ma = a[aidx] + (aidx+1) * m;
      if (ma < n) level[mm-1].push_back(ma);
    }
  }

  // for (int i=0; i<level.size();i++) for (int j=0;j<level.size();j++) cout << level[i][j];

  for (auto eachLevel : level) {
    for (int num=0;num<n;num++) {
      auto res = find(eachLevel.begin(), eachLevel.end(), num);
      if (res == eachLevel.end()) {
        cout << num << endl;
      } else {
        continue;
      }
    }
  }

  return 0;
}
