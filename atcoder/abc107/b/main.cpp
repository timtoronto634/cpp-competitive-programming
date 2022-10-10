#include <bits/stdc++.h>
using namespace std;


void printM(vector<vector<char>> m) {
  for (int i=0; i<m.size();i++) {
    for (int j=0; j<m[0].size();j++) {
      cout << m[i][j];
    }
    cout << endl;
  }
}

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> mat(h, vector<char>(w));
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      cin >> mat[i][j];
    }
  }

  vector<vector<char>> v(0);
  for (int i=0;i<h;i++) {
    bool blank = true;
    for (int j=0;j<w;j++) {
      if (mat[i][j] == '#') {
        blank = false;
      }
    }
    if (!blank) {
      vector<char> row(0);
      v.push_back(mat[i]);
    }
  }


  vector<vector<char>> out(v.size());
  // cout << "vsize: " << v[0].size() << endl;
  for (int j=0;j<v[0].size();j++) {
    bool remove = true;
    for (int i=0;i<v.size();i++) {
        if (v[i][j] == '#') {
          remove = false;
        }
      }
    if (!remove) {
      for (int i=0;i<out.size();i++) {
        out[i].push_back(v[i][j]);
      }      
    }
    // cout << "mid: ";
    // printM(out);
  }
  printM(out);
  return 0;
}
