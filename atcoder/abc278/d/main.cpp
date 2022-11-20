#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, q;
  cin >> n;
  map<int, ll> mm;
  ll ni;
  for (int i=1;i<=n;i++) {
    cin >> ni;
    mm[i] = ni;
  }
  cin >> q;
  int t, iq, x;
  ll initval;
  for (int i=0;i<q;i++) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      initval = x;
      mm.clear();
    } else if (t==2) {
      cin >> iq >> x;
      if (mm.count(iq) == 0) {
        mm[iq] = initval;
      }
      mm[iq] += x;
    } else {
      cin >> iq;
      if (mm.count(iq) == 0) {
        mm[iq] = initval;
      }
      cout << mm[iq] << endl;
    }
  }
  return 0;
}
