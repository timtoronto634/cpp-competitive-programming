#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll MOD=998244353;
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
  int n;
  cin >> n;
  vector<ll> cards(n);
  for (int i=0;i<n;i++) {
    cin >> cards[i];
  }
  ll curMax = cards[0];
  // k : num of cards
  map<int,int> counts;
  for (int k=1;k<=n;k++) {
    counts[cards[k-1]]++;
    ll out = 0;
    // double out = 0.;
    ll p = modInv(pow(k,2));
    // double p = 1. / pow(k,2);
    // cout << "p for " << k << " is: " << p << endl;
    for (int c=0;c<k;c=c) {
      ll num;
      for (auto el : counts) {
        num = el.first;
        c += el.second;
        ll times = el.second;
        // c: idx of card
        ll numOcc = (2 * c + 1)%MOD;
        // ll numOcc = (2 * c + 1);
        out += ((num * numOcc %MOD) * p %MOD )* times % MOD;
        // out += (cards[c] * numOcc) * p ;
      }
      // out %= MOD;
    }
    cout << out << endl;
  }
  return 0;
}
