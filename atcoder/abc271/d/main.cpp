#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n,s,ai,bi;
  cin >> n >> s;
  deque<int> sums(1,0);
  deque<vector<char>> paths(1);
  for (int i=0;i<n;i++) {
    set<int> seen;
    cin >> ai >> bi;
    int curLen =  sums.size();
    for (int i=0;i<curLen;i++) {
      int curSum = sums.front();
      sums.pop_front();
      vector<char> path = paths.front();
      paths.pop_front();

      if (curSum + ai <= s && (seen.count(curSum+ai) == 0)) {
        vector<char> nexta;
        sums.push_back(curSum+ai);
        copy(path.begin(), path.end(), back_inserter(nexta));
        nexta.push_back('H');
        paths.push_back(nexta);
        seen.insert(curSum+ai);
      }
      if (curSum + bi <= s && (seen.count(curSum+bi) == 0)) {
        vector<char> nextb;
        sums.push_back(curSum+bi);
        copy(path.begin(), path.end(), back_inserter(nextb));
        nextb.push_back('T');
        paths.push_back(nextb);
        seen.insert(curSum+bi);
      }
    }
  }
  for (int i=0;i<sums.size();i++) {
    if (sums[i] == s) {
      cout << "Yes" << endl;
      for (int j=0;j<paths[i].size();j++) {
        cout << paths[i][j];
      }
      cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
    return 0;
}
