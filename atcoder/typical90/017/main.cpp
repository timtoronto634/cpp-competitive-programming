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
  int adj[n][n];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) adj[i][j]=0;
  for (int i=0;i<m;i++) {
    cin >> from>> to;
    from--;
    to--;
    lines[i] = line{from,to};
    adj[from][to]++;
    adj[to][from]++;
  }

  // for each point, precalc the cumulative number of lines from the start point to each point
  // 0: [0, 0, 1, 2, 2, 2]
  // 1: [0, 0, 0, 0, 1, 1]
  // 2: [1, 1, 1, 1, 1, 1]
  // 3: [1, 1, 1, 1, 1, 1]
  // 4: [0, 1, 1, 1, 1, 1]
  // 5: [0, 0, 0, 0, 0, 0]
  // map<int,int> distances;
  int cumul[n][n];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) cumul[i][j] = j == 0 ? adj[i][j] : cumul[i][j-1]+adj[i][j];

  // for each line, loop till the other end while counting how many lines crosses
  // for [1,4]
  // count line start from point 2 (count (4+1) to (1-1))
  //   2[5] - 2[4] = 1 - 1 = 0
  //   2[1-1] = 1
  //   total 1
  // count line start from point 3 (count (4+1) to (1-1))
  //   3[4+1] - 3[4] = 1 - 1 = 0
  //   3[1-1] = 1
  //   total 1
  // for [1,4]  total 2
  // for [0,3]
  // count line start from point 1 (count (3+1) to (0-1=5)) 1[5]-1[3] = 1
  // count line start from point 2 (count (3+1) to (0-1=5)) 2[5]-2[3] = 0
  // total 1
  // for [0,2]
  // count line start from point 1 (count (2+1) to (0-1=5)) 1[5]-1[2] = 1
  // total 1
  // total 4 overall
  ll total =0;
  for (line eachl : lines) {
    for (int startp = eachl.from+1;startp<eachl.to;startp++) {
      total += cumul[startp][n-1] - cumul[startp][eachl.to];
      if (eachl.from != 0) {
        total += cumul[startp][eachl.from-1];
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
