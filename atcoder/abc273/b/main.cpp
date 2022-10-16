#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll x, k;
  cin >> x >> k;
  ll div = 1;
  for (int i=1;i<=k;i++) {
    div *= 10;
    ll up = x / div;
    ll mod = x % div;
    if (mod == 0) {
      x = up * div;
      continue;
    }
    ll condition = mod / (div / 10);
    if (condition >= 5) {
      x = (up+1) * (div);
    } else {
      x = up * div;
    }
    // cout << "vars: " << div << " " << up << " " << x << endl;
  }
  cout << x << endl;
  return 0;
}
