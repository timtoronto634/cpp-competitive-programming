#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll sum = 0;
  for (int i=0;i<n;i++) sum+=abs(a[i]-b[i]);
  cout << sum << endl;

  return 0;
}
