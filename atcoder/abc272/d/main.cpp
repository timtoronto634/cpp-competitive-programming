#include <bits/stdc++.h>

using namespace std;

bool is_valid_move(int xx, int yy, vector<vector<int>> &v) {

  if (xx==0 && yy==0) return false;
  if (xx <0 || yy < 0 || xx >= v.size() || yy >= v.size()) return false;
  return v[xx][yy] == 0;
}

int main() {
  int m, n;
  cin >> n >> m;

  vector<pair<int,int>> moves(0);
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=n;j++) {
      if (i*i + j*j == m) {
        moves.push_back(make_pair(i, j));
        moves.push_back(make_pair(-1 * i, j));
        moves.push_back(make_pair(i, -1 * j));
        moves.push_back(make_pair(-1 * i, -1 * j));
        moves.push_back(make_pair(j, i));
        moves.push_back(make_pair(j, -1 * i));
        moves.push_back(make_pair(-1 * j, i));
        moves.push_back(make_pair(-1 * j, -1 * i));
      }
    }
  }

  vector<vector<int>> out(n, vector<int>(n, 0));

  queue<pair<int,int>> cells;
  cells.push(make_pair(0,0));
  int numm = 1;
  while ((cells.size() != 0)) {
    int length = cells.size();
    for (int i=0;i<length;i++) {
      int x,y;
      x = cells.front().first;
      y = cells.front().second;
      cells.pop();
      for (auto m : moves) {
        int xx = x + m.first;
        int yy = y + m.second;
        if (!is_valid_move(xx, yy, out)) continue;
        out[xx][yy] = numm;
        cells.push(make_pair(xx, yy));
      }
    }
    numm++;
  }

  // fill -1
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (i==0 && j==0) continue;
      if (out[i][j]==0) out[i][j] = -1;
    }
  }



  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (j!=0) cout << " ";
      cout << out[i][j];
    }
    cout << endl;
  }

  return 0;
}
