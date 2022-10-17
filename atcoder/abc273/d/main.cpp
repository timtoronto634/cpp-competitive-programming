#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll h,w;
  ll rs, cs;
  cin >> h >> w >> rs >> cs;
  int num_block;
  cin >> num_block;

  // create and fill surroundings
  vector<vector<int>> mat(h+2, vector<int>(w+2, 0));
  for (int i=0;i<h+2;i++) {
    mat[i][0] = 1;
    mat[i][w+1] = 1;
  }
  for (int j=0;j<w+2;j++) {
    mat[0][j] = 1;
    mat[h+1][j] = 1;
  }

  int r,c;
  for (int m=0;m<num_block;m++) {
    cin >> r >> c;
    mat[r][c] = 1;
  }

  int num_op;
  cin >> num_op;

  string d;
  int length;
  auto cur = make_pair(rs, cs);
  for (int op=0;op<num_op;op++) {
    cin >> d >> length;

    int rd=0, cd=0;
    if (d == "L") {rd = 0; cd = -1;}
    if (d == "R") {rd = 0; cd = 1;}
    if (d == "U") {rd = -1; cd = 0;}
    if (d == "D") {rd = 1; cd = 0;}

    // mat, cur, rd, cd, l
    for (int m=1;m<=length;m++) {
      if (mat[cur.first + rd][cur.second + cd] == 0) {
        cur.first = cur.first+rd;
        cur.second = cur.second +cd;
      } else {
        break;
      }
    }

    cout << cur.first << " " << cur.second << endl;;
  }


  return 0;
}
