#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct line {int from; int to;};

int main() {
  int n,m;
  cin >> n >> m;

  // store input
  // [[1,4],[0,3],[0,2]]
  vector<line> lines(m);
  int from, to;
  // int adj[n][n];
  // for (int i=0;i<n;i++) for (int j=0;j<n;j++) adj[i][j]=0;
  map<int, vector<int>> adjmap;
  for (int i=0;i<m;i++) {
    cin >> from>> to;
    from--;
    to--;
    lines[i] = line{from,to};
    adjmap[from].push_back(to);
    adjmap[to].push_back(from);
  }

  // sort each vec
  for (auto &each : adjmap) {
    auto &eachv = each.second;
    sort(eachv.begin(), eachv.end());
  }

  ll total =0;
  for (line eachl : lines) {
    for (int startp = eachl.from+1;startp<eachl.to;startp++) {
      if (adjmap.count(startp) == 0) continue;
      vector<int> &adj = adjmap[startp];
      auto index = lower_bound(adj.begin(), adj.end(), eachl.to);
      if (index != adj.end()) {
        total += distance(index, adj.end());
      }
      
      auto indexS = lower_bound(adj.begin(), adj.end(), eachl.from);
      if (indexS == adj.end()) {
        total += adj.size();
      } else {

        total += distance(adj.begin(), indexS);
      }
    }
  }

  // halves at the end
  // return 2
  cout << total/2 << endl;
  return 0;
}


// 6 3
// 2 5 -> 1 4
// 1 4 -> 0 3
// 1 3 -> 0 2
