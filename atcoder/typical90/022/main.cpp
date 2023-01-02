#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  ll part = gcd(gcd(a,b), c) ;
  cout << (max(a/part-1, 0LL)+max(b/part-1,0LL)+max(c/part-1,0LL)) << endl;
  return 0;
}
