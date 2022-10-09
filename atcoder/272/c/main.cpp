#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i=0;i<n;i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  // odd
  int odds = -1;
  int oddq = -1;
  for (int j=v.size()-1; j>=0;j--) {
    if (v[j] & 1) {
      // cout << v[j] << endl;
      if (odds == -1) {
        odds = v[j];
      } else {
        oddq = odds + v[j];
        break;
      }
    }
  }

  // even
  int e = -1;
  int evenq = -1;
  for (int j=v.size()-1; j>=0;j--) {
    if (!(v[j] & 1)) {
      // cout << v[j] << endl;
      if (e == -1) {
        e = v[j];
      } else {
        evenq = e + v[j];
        break;
      }
    }
  }
  cout << max(evenq, oddq) << endl;
  return;
}


int main() {
    solve();
  return 0;
}
