#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct line {int from; int to;};

bool crossed(line s, line t) {
  if (s.from < t.from && t.from < s.to && s.to < t.to) return true;
  if (t.from < s.from && s.from < t.to && t.to < s.to) return true;
  return false;
}

int main() {
  int n,m;
  cin >> n >> m;

  vector<line> lines(m);
  int from, to;
  for (int i=0;i<m;i++) {
    cin >> from>> to;
    from--;
    to--;
    lines[i] = line{from,to};
  }

  ll total =0;
  for (int i=0;i<m;i++) {
    for (int j=i+1;j<m;j++) {
      if (crossed(lines[i], lines[j])) total++;
    }
  }
  cout << total << endl;
  return 0;
}


// 6 3
// 2 5 -> 1 4
// 1 4 -> 0 3
// 1 3 -> 0 2
