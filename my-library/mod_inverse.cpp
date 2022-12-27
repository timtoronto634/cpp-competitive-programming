#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

// https://qiita.com/e869120/items/b4a0493aac567c6a7240#3-10-%E9%80%86%E5%85%83%E3%81%AB%E5%AD%A6%E3%81%B6%E3%83%95%E3%82%A7%E3%83%AB%E3%83%9E%E3%83%BC%E3%81%AE%E5%B0%8F%E5%AE%9A%E7%90%86%E3%83%AC%E3%83%99%E3%83%ABstar3
// Fermat's little theorem
// MOD: prime number
// pow(a, p) % p = a
// pow(a, p-1) % p = 1
// pow(b, p-1) ≡ 1 (mod p) <=> b * a * pow(b,p-2) ≡ a (mod p)
// x = a * pow(b,p-2)
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
  return a * (exponentialMod(b, mod-2, mod)) % mod;
}

// calculates n! / ((n-r)! r!)
long long nCrMod(long long n, long long r, long long mod) {
  if (n < r) return 0;
  long long numerator = 1;
  long long denominator = 1;
  for (int i=1;i<=n;i++) { numerator *= i; numerator %= mod; }
  for (int i=1;i<=(n-r);i++) { denominator *= i; denominator %= mod; }
  for (int i=1;i<=r;i++) { denominator *= i; denominator %= mod; }
  return invModDiv(numerator, denominator, mod);
}