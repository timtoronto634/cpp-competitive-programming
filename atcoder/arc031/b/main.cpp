#include <bits/stdc++.h>
using namespace std;

bool is_one_island(vector<string>);
void explore_island(vector<string>&, int, int);
bool is_valid_move(vector<string>&, int, int);

int main() {
  vector<string> v(10);
  for (int i=0;i<10;i++) {
    string s;
    cin >> s;
    v[i] = s;
  }
  for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
      if (v.at(i).at(j) == 'o') continue;
      v[i][j] = 'o';
      if (is_one_island(v)) {
        cout << "YES" << endl;
        return 0;
      }
      v[i][j] = 'x';
    }
  }
  cout << "NO" << endl;
}

bool is_one_island(vector<string> v) {
  for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
      if (v[i][j] == 'o') {
        explore_island(v, i,j);

        bool one = true;
        // check if all island is visited
        for (int i=0;i<10;i++) {
          for (int j=0;j<10;j++) {
            if (v[i][j] == 'o') {
              one = false;
            }
            if (v[i][j] == 'v') {
              v[i][j] = 'o';
            }
          }
        }
        if (one) return true;
      }
    }
  }
  return false;
}

void explore_island(vector<string> &v, int i, int j){
  if (!is_valid_move(v, i, j)) {
    return;
  }
  v[i][j] = 'v';
  explore_island(v, i-1,j);
  explore_island(v, i+1,j);
  explore_island(v, i,j+1);
  explore_island(v, i,j-1);
  return ;
}

bool is_valid_move(vector<string> &v, int i, int j) {
  if (i < 0 || j < 0) {
    return false;
  }
  if (i >= 10 || j >= 10) {
    return false;
  }
  return v[i][j] == 'o';
}

