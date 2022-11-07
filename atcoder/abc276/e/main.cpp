#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool isValid(vector<vector<char>> &masu, int r, int c) {
  int h=masu.size(), w = masu[0].size();

  if (r < 0 || c < 0|| r>=h || c >= w || masu[r][c] == '#' || masu[r][c] == 'S') {
    return false;
  }
  return true;
}

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> masu(h, vector<char>(w, '.'));
  int sr, sc;
  for (int r=0;r<h;r++) {
    for (int c=0;c<w;c++) {
      char ci;
      cin >> ci;
      masu[r][c] = ci;
      if (ci=='S') {
        sr = r;
        sc = c;
      }
    }
  }
  queue<vector<int>> q;
  //first 
  char label = 'a';
  if (isValid(masu, sr+1, sc)) {
    masu[sr+1][sc] = label;
    q.push(vector<int>{sr+1,sc});
  }
  label = 'b';
  if (isValid(masu, sr, sc-1)) {
    masu[sr][sc-1] = label;
    q.push(vector<int>{sr,sc-1});
  }
   label = 'c';
  if (isValid(masu, sr-1, sc)) {
    masu[sr-1][sc] = label;
    q.push(vector<int>{sr-1,sc});
  }
   label = 'd';
  if (isValid(masu, sr, sc+1)) {
    masu[sr][sc+1] = label;
    q.push(vector<int>{sr,sc+1});
  }

  vector<vector<int>> dir = {{0,1}, {0, -1}, {1,0}, {-1,0}};
  while (q.size() > 0) {
    int num_q = q.size();
    for (int x=0;x<num_q;x++) {
      auto cord = q.front();
      q.pop();
      int r = cord[0], c = cord[1];
      for (auto d : dir) {
        if (!isValid(masu, r+d[0], c+d[1])) continue;
        if (masu[r+d[0]][c+d[1]] == '.') {
          masu[r+d[0]][c+d[1]] = masu[r][c];
          q.push(vector<int>{r+d[0], c+d[1]});
        } else if (masu[r+d[0]][c+d[1]] == masu[r][c]) {
          continue;
        } else {
          cout << "Yes" << endl;
          return 0;
        }
      }

    }
  }
  cout << "No" << endl;
  return 0;
}
