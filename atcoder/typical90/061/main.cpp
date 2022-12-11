#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int q, t, x;
  cin >> q;
  vector<int> two, one;
  for (int i=0;i<q;i++) {
    cin >> t >> x;
    if (t == 3) {
      int out;
      if (x <= one.size()) {
        out = one[one.size()-x];
      } else {
        out = two[x-one.size()-1];
      }
      cout << out << endl;
    } else if (t == 1) {
      one.push_back(x);
    } else {
      two.push_back(x);
    }
  }
  return 0;
}
