#include <bits/stdc++.h>
#include "atcoder/modint.hpp"
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long int;

ll MOD = 998244353;
// cite: https://math.nakaken88.com/textbook/cp-modulo-operation-inverse-element/
long long modPow(long long x, long long a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(ll x) {
  return modPow(x, MOD - 2);
}

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<mint> v(n+1, 0);
  v[0] = 1;
  mint m_inv = 1 / mint(m);
  for (int i=0; i<k;i++) {
    vector<mint> next(n+1,0);
    next[n] = v[n];
    for (int j=0; j<n;j++) { // no move from v[n]
      if (v[j] == 0) continue;
      for (int advance = 1; advance <= m; advance++) {
        int target;
        if (j+advance > n) {
          target = 2 * n - (j+advance);
        } else {
          target = j + advance;
        }
        next[target] += v[j] * m_inv;
      }
    }
    v = next;
  }
  // ll x = accumulate(v.begin(), v.end(), 0);
  // ll x = pow(m, k);
  // ll y = v[n];
  cout << v[n].val() << endl;
  // cout << float(y) / float(x) << endl;

  return 0;
}
