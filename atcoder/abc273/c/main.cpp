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
    // cout << v[i]  << endl;
    cnt.insert(make_pair(v[i], 1));
    // cout << cnt[v[i]] << endl;
  }
  int rest = cnt.size();
  vector<int> out(n+1, 0);
  int idx = 1;
  for (auto x : cnt) {
    // cout << x.first << endl;
    rest--;
    out[idx] = rest;
    
  }
  for (int i=1;i<=n+1;i++) {
    cout << out[i] << endl;
  }

  return 0;
}
