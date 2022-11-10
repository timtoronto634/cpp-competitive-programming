#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll n;
  string s;
  cin >> n >> s;

  // create hashmap of num_consecutive : cnts of the conetinue
  // 2 : 1, 1 : 2
  map<ll, ll> cont2cnts;
  char cur = s[0];
  ll cont = 1;
  for (ll i=1;i<n;i++) {
    if (s[i] == cur) {
      cont++;
    } else {
      cont2cnts[cont]++;
      cur = s[i];
      cont = 1;
    }
  }
  cont2cnts[cont]++;
  vector<ll> keys;
  for (auto cc : cont2cnts) {
    keys.push_back(cc.first);
  }

  // 2 for loop while adding the a x b x (cnt_a x cnt_b) or a x a x (cnt_a x (cnt_a-1))
  // 2x2x(1x1-1) + 2x1x(1x2) + 1x1x(2x2-1)
  ll sum = 0;
  for (ll i=0;i<keys.size();i++) {
    for (ll j=i;j<keys.size();j++) {
      auto cc1 = cont2cnts[keys[i]];
      auto cc2 = cont2cnts[keys[j]];

      if (i == j) {
        sum += keys[i] * keys[j]  * (cc1 * (cc2 - 1) / 2);
      } else {
        sum += keys[i] * keys[j] * (cc1 * cc2);
      }
    }
  }
  cout << sum << endl;

  return 0;
}
