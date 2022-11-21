#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

  int dp[301][301][301];

int main() {
  int H, W, n, h, w;
  cin >> H >> W >> n >> h >> w;
  vector<vector<int>> vv(H, vector<int>(W));
  // map<int, vector<vector<int, int>>> num2cood;
  // map<int, int> num2cnts;
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) {
      cin >> vv[i][j];
      // num2cnts[vv[i][j]]++;
    }
  }

  // i,jを含みi,j より右下の範囲に値kがいくつあるか
  for (int k=1;k<=n;k++) {
    for (int i=H-1;i>=0;i--) {
      for (int j=W-1;j>=0;j--) {
        dp[i][j][k] = dp[i+1][j][k]+dp[i][j+1][k]-dp[i+1][j+1][k] + (vv[i][j]==k);
      }
    }
  }

  for (int i=0;i<H-h+1;i++) {
    for (int j=0;j<W-w+1;j++) {
      int sum = 0;
      for (int k=1;k<=n;k++) {
        if (dp[0][0][k] - (dp[i][j][k] - dp[i+h][j][k] - dp[i][j+w][k] + dp[i+h][j+w][k]) >0) sum++;
      }
      if (j==W-w) cout << sum << endl;
      else cout << sum << " ";
    }
  }

  return 0;
}
