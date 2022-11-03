#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


// dp[部分列のどこまでみたか][どこの都市にいるか] = 最小の長さ
int main() {
  int n, m,k;
  cin >> n >> m >> k;
  vector<vector<int>> edgesFrom;
  for (int i=0;i<m;i++) {
    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];
    abc[0] -=1;
    abc[1] -= 1;
    edgesFrom.push_back(abc);
  }
  vector<int> e(k);
  for (int i=0;i<k;i++) cin >> e[i];

  vector<ll> cur(n, LLONG_MAX);
  cur[0] = 0;
  for (int kk=1;kk<=k;kk++) {
    int a = edgesFrom[e[kk-1]-1][0];
    int b = edgesFrom[e[kk-1]-1][1];
    int c = edgesFrom[e[kk-1]-1][2];
    if (cur[a] == LLONG_MAX) continue;
    cur[b] = min(cur[a] + c, cur[b]);
  }
  ll out = cur[n-1];
  if (out == LLONG_MAX) {
    cout << -1 << endl;
  } else {

  cout << out << endl;
  }
    return 0;
}
