#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> av(n);
  for (int i=0;i<n;i++) {
    cin >> av[i];
  }
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(2,-1)));
  // dp[0][0][1] = -1; this is needless.
  if (av[0] <= m) dp[0][av[0]][1] = 0;
  for (int i=0;i<n;i++) {
    // remove all (1 operation) always lead to sum of 0
    int total = 0;
    dp[i][total][0] = 1;
  }
  for (int i=1;i<n;i++) {
    for (int total=1;total<=m;total++) {
      // 0 (i.e. not using ai)
      int nouse = -1;
      if (dp[i-1][total][0] >= 0) {
        // left is removed, so no increment
        nouse = dp[i-1][total][0];
      }
      if (dp[i-1][total][1] >= 0) {
        nouse = nouse == -1 ? dp[i-1][total][1] + 1 : min(nouse, dp[i-1][total][1] + 1);
      }
      dp[i][total][0] = nouse;
      // 1
      if (total-av[i] < 0) continue;
      int use = -1;
      if (dp[i-1][total-av[i]][0] >= 0) {
        use = dp[i-1][total-av[i]][0];
      } 
      if (dp[i-1][total-av[i]][1] >= 0) {
        use = use == -1 ? dp[i-1][total-av[i]][1] : min(use, dp[i-1][total-av[i]][1]);
      }
      dp[i][total][1] = use;
    }
  }
  for (int x=1;x<=m;x++) {
    if (dp[n-1][x][0] <0) cout << dp[n-1][x][1] <<endl;
    else if (dp[n-1][x][1] <0) cout << dp[n-1][x][0] <<endl;
    else cout << min(dp[n-1][x][0], dp[n-1][x][1]) <<endl;
  }

  return 0;
}
