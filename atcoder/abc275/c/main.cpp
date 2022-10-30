#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  vector<vector<int>> ss(9, vector<int>(9,0));
  vector<vector<int>> dots;
  for (int i=0;i<9;i++) {
    string s;
    cin >> s;
    for (int j=0;j<9;j++) {
      if (s[j] == '#') {
        ss[i][j] = 1;
        dots.push_back(vector<int>{i,j});
      }
    }
  }
  int cnts = 0;
  for (int i=0;i<dots.size();i++) {
    auto topleft = dots[i];
    int r = topleft[0], c=topleft[1];
    for (int j=i+1;j<dots.size();j++) {
      auto topright = dots[j];
      int rr = topright[0], cc = topright[1];
      int rrr = r + (cc - c), ccc = c - (rr - r);
      int rrrr = rr + (cc - c), cccc = cc - (rr - r);
      if (rrr < 0 || rrrr < 0 || ccc < 0 || cccc < 0 ||
          rrr >= 9 || rrrr >= 9 || ccc >= 9 || cccc >= 9) continue;
      if (ss[rrr][ccc] == 1 && ss[rrrr][cccc] == 1) {
        cnts++;
      }
    }
  }
  cout << cnts / 2 << endl;



  return 0;
}
