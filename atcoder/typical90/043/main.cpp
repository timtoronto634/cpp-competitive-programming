#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int mat[1002][1002];
int main() {
  int h,w, rs, cs, rt, ct;
  cin >> h >> w >> rs >> cs >> rt >> ct;
  rs++;
  cs++;
  rt++;
  ct++;
  vector<vector<int>> rows(h+2, vector<int>()), cols(w+2, vector<int>);
  for (int i=0;i<=h+1;i++) {
    for (int j=0;j<=w+1;j++) {
      if (i==0 || j==0 || i==h+1 || j==w+1) {
        mat[i][j] = '#';
        continue;
      } else {
        cin >> mat[i][j];
      }
      if (mat[i][j] == '#') {
        rows[i].push_back(j);
        cols[j].push_back(i);
      }
    }
  }
  set<pair<int,int>> visited;
  queue<pair<int,int>> q;
  q.push(make_pair(rs,cs));
  while (!q.empty()) {
    auto el = q.front();
    int r = el.first, c = el.second;
    auto nextc = upper_bound(rows[r].begin(), rows[r].end(), r);
  }



  return 0;
}
