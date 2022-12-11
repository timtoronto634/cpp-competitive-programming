#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int maximum_same(vector<int> R) {
  map<int, int> Map; int ret = 0;
  for (int i=0; i< R.size(); i++) {
    Map[R[i]]++;
    ret = max(ret, Map[R[i]]);
  }
  return ret;
}

int main() {
  int h, w, p;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w));
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      cin >> p;
      grid[i][j] = p;
    }
  }

  int maxAppear = 1;
  for (int i=1; i < (1 << h); i++) {
    // map<int, int> validTimes; // for this combination, count which number appear how many times
    vector<int> R;
    for (int col=0;col<w;col++) {
      int cur = 0; bool flag = false;
      for (int k=0;k<h;k++) {
        if ((i & (1 << k)) == 0) continue;
        if (cur == 0) {
          cur = grid[k][col];
        } else {
          if (cur != grid[k][col]) {
            flag = true;
            break;
          }
        }
      }
      if (flag == false) {
        R.push_back(cur);
      }
    }

    int cnth = 0, cntW = maximum_same(R);
    for (int j=0;j<h;j++) {
      if ((i & (1 << j)) != 0) cnth++;
    }
    maxAppear = max(maxAppear, cnth*cntW);
  }
  cout << maxAppear << endl;

  return 0;
}
