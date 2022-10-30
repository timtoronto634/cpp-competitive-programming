#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll mod = 998244353;
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  ll left = ((a % mod) * (b % mod) % mod) * (c % mod) % mod;
  ll right = (((d % mod) * (e % mod) % mod) * (f % mod)) % mod;
  if (left < right) {
    left += mod;
  }
  cout << left - right << endl;
  return 0;
}
