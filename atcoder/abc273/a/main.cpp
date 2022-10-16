#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll n;
  cin >> n;
  ll out = 1;
  for (int i=1;i<=n;i++) {
    out *= i;
  }
  cout << out << endl;
  return 0;
}
