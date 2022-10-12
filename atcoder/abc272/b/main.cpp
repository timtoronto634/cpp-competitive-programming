#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,m;
  int k, vis[105][105];
  int a[105];

  cin >>n>>m;

  for (int i=1;i<=m;i++) {
    cin >> k;
    for (int j=1;j<=k;j++) cin >> a[j];
    for (int j=1;j<=k;j++) for (int t=j+1;t<=k;t++){
      vis[a[j]][a[t]] = vis[a[t]][a[j]]=1;
    }
  }
  for (int i=1;i<=n;i++)
  for (int j=i+1;j<=n;j++) {
    if (vis[i][j] == 0) {
      cout << "No"<<endl;return;
    }
  }

    cout << "Yes" << endl;
}

int main() {
    solve();
  return 0;
}
