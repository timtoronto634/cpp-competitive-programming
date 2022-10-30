#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll teneighteen = 1e8;
ll memo[teneighteen];

ll fib(long long x) {
  if (x==0) return 1;
  if (x==1) return 2;
  if (x < 1e8 && memo[x] != 0) return memo[x];
  ll two = x / 2;
  ll three = x / 3;
  ll out = fib(two) + fib(three);
  if (x < 1e8) memo[x] = out;
  return out;
}

int main() {
  ll n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}
