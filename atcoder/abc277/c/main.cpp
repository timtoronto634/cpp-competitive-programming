#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, ai,bi;
  cin >> n;
  set<int> visited;
  visited.insert(1);
  map<int, vector<int>> hashigo;
  for (int i=0;i<n;i++) {
    cin >> ai >> bi;
    hashigo[ai].push_back(bi);
    hashigo[bi].push_back(ai);
  }
  queue<int> cur;
  cur.push(1);
  int curmax = 1;
  while (!cur.empty()) {
    int tak = cur.front();
    cur.pop();
    for (int i=0; i<hashigo[tak].size();i++) {
      int nex = hashigo[tak][i];
      if (visited.count(nex) == 1) continue;
      visited.insert(nex);
      cur.push(nex);
      curmax=max(curmax, nex);
    }
  }
  cout << curmax << endl;
  return 0;
}
