#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, q, ti, a, b;
  cin >> n >> q;
  map<int,set<int>> follow;
  for (int i=0;i<q;i++) {
    cin >> ti;
    cin >> a >> b;
    if (ti == 1) {
      follow[a].insert(b);
    }
    else if (ti == 2) {
      follow[a].erase(b);
    }
    else {
      if (follow[a].count(b) == 1 && follow[b].count(a) == 1) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }

  }

  return 0;
}
