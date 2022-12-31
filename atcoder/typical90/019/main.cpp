#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

// dp[l][r] = cost
ll dp[410][410];
int N;
ll A[410];
int main() {
  cin >> N;
  for (int i=1;i<=N*2;i++) {
    cin >> A[i];
  }
  // initialize
  for (int i=1; i<=N*2;i++) {
    for (int j=i+1;j<=N*2;j+=2) {
      dp[i][j] = INT_MAX;
      if (j==i+1) dp[i][j] = abs(A[i]-A[j]);
    }
  }

  // range dp
  for (int diff=3;diff<=N*2;diff+=2) { // 5
    for (int left=1;left<=N*2-diff;left++) { // 1
      // remove (left,left+diff) at the end
      dp[left][left+diff] = min(
        dp[left][left+diff],
        abs(A[left] - A[left+diff]) + dp[left+1][left+diff-1]
      );
      // (left, middle), (middle+1,left+diff)
      for (int middle=left+1; middle<left+diff-1;middle+=2) { // 2
        dp[left][left+diff] = min(dp[left][left+diff], dp[left][middle]+dp[middle+1][left+diff]);
      }
    }
  }
  cout << dp[1][N*2] << endl;
  

  return 0;
}
