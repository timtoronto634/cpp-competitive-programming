#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<ll> v(n);
  int ai;
  for (int i=0;i<n;i++) {
    cin >> ai;
    v[i] = ai % p;
  }
  ll cnt = 0;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      for (int k=j+1;k<n;k++) {
        for (int l=k+1;l<n;l++) {
          for (int m=l+1;m<n;m++) {
            if ((((v[i] * v[j] % p) * v[k] % p) * v[l] % p) * v[m] % p == q) {
              cnt++;
            }
          }
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
