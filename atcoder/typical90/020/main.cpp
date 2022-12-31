#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll a, b, c;

ll numPow(ll c, ll b) {
  if (b==1) return c;
  ll half = numPow(c, (b/2));
  if (b & 1 == 1) return half * half * c;
  else return half * half;
}

int main() {
  cin >> a >> b >> c;
  cout << ((a < numPow(c,b)) ? "Yes" : "No") << endl;
  return 0;
}
