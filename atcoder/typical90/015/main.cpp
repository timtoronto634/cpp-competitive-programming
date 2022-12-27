#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


// exponentialMod calculates pow(b, power) % mod
long long exponentialMod(long long b, long long power, long long mod) {
  long long result = 1, multiply = b;
  for (int i=0;i<31;i++) {
    if ((power & (1 << i)) != 0) { result *= multiply; result %= mod; }
    multiply *= multiply; multiply %= mod;
  }
  return result;
}

// what we want: x of  bx≡a(modp)  i.e.  a/b (mod p)
long long invModDiv(long long a, long long b, long long mod) {
  return (a * exponentialMod(b, mod-2, mod)) % mod;
}

ll memo[1000000];
long long  factorial(int n, ll mod) {
  if (n <= 1) return 1;
  if (memo[n] != 0) return memo[n];
  ll result = factorial(n-1, mod) * n % mod;
  memo[n] = result;
  return result;
}

// calculates n! / ((n-r)! r!) mod
long long nCrMod(long long n, long long r, long long mod) {
  if (n < r) return 0;
  long long numerator = factorial(n, mod);
  long long denominator = factorial(n-r, mod) * factorial(r, mod) % mod;
  return invModDiv(numerator, denominator, mod);
}

int main() {
  int n;
  cin >> n;


  ll MODULE = pow(10,9)+7;

  for (int div=1;div<=n;div++) {
    ll plus=0;
    for (int elcnt=1;(elcnt-1)*div<=n;elcnt++) {
      plus += nCrMod(n-((div-1)*(elcnt-1)), elcnt, MODULE);
      plus %= MODULE;
    }
    cout << plus << endl;
  }

  return 0;
}
