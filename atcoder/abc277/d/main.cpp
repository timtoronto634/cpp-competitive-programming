#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n,m;
  int ai;
  cin >> n >> m;
  vector<int> origin;
  // vector<pair<int, int>> v;

  for (int i=0;i<n;i++) {
    cin >> ai;
    origin.push_back(ai);
    // v.push_back(make_pair(ai % m, ai));
  }
  // sort(v.begin(), v.end());
  sort(origin.begin(), origin.end());
  vector<ll> sums;
  sums.push_back(origin[0]);
  for (int i=1;i<n;i++) {
    if (origin[i] == origin[i-1] || origin[i] == origin[i-1]) {
      sums[sums.size()-1] += origin[i];
    } else {
      sums.push_back(origin[i]);
    }
  }
  if (sums.size() >= 2 && origin[0] == ((origin[origin.size()-1] + 1) % m)) {
    sums[0] += sums[sums.size()-1];
    sums.pop_back();
  }
  ll maxval = 0;
  for (int i=0;i<sums.size();i++) {
    maxval = max(maxval, sums[i]);
  }
  cout << accumulate(sums.begin(), sums.end(), 0)-maxval << endl;
    return 0;
}
