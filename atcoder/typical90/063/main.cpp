#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<vector<int>> generateComb(int n) {
  vector<vector<int>> out;
  out.push_back(vector<int>(0));
  for (int i=0;i<n;i++) {
    int sizen = out.size();
    for (int j=0;j<sizen;j++) {
      vector<int> fromv = out[j];
      vector<int> newv;
      copy(fromv.begin(), fromv.end(), back_inserter(newv) );
      newv.push_back(i);

      out.push_back(newv);
    }
  }
  return out;
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
  vector<vector<int>> combination = generateComb(h);
  
  int maxAppear = 1;
  for (auto& comb: combination) {
    map<int, int> validTimes; // for this combination, count which number appear how many times
    for (int col=0;col<w;col++) {
      int cur = 0;
      bool valid = true;
      for (int rowi=0; rowi<comb.size(); rowi++) {
        int row = comb[rowi];
        if (cur == 0) {
          cur = grid[row][col];
        } else {
          if (cur != grid[row][col]) {
            valid = false;
            break;
          }
        }
      }
      if (valid) {
        validTimes[cur] += comb.size();
      }
    }
    for (auto eachPair : validTimes) {
      maxAppear = max(maxAppear, eachPair.second);
    }
  }
  cout << maxAppear << endl;

  return 0;
}
