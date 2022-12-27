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

// calculates n! / ((n-r)! r!) mod
long long nCrMod(long long n, long long r, long long mod) {
  if (n < r) return 0;
  long long numerator = 1;
  long long denominator = 1;
  for (int i=1;i<=n;i++) { numerator *= i; numerator %= mod; }
  for (int i=1;i<=(n-r);i++) { denominator *= i; denominator %= mod; }
  for (int i=1;i<=r;i++) { denominator *= i; denominator %= mod; }
  return invModDiv(numerator, denominator, mod);
}

int main() {
  int n;
  cin >> n;


  ll MODULE = pow(10,9)+7;

  // vector<ll> ans(n+1);
  // ans[n] = n;
  // i >= (n / 2) の間は (n-i) を足していけばいい

  // (n/2) > i >= (n/3) の間は 2個のパターンと3個のパターンがある
  // n=7 i=3  のとき、 2個: (1,4)(2,5)(3,6)(4,7) 3個: (1,4,7) → 5を足す
  // 2個とは、7-3 個つまり (n-i)個ある
  // 3個とは、7-6 個つまり (n- (i*2))個ある

  // n=7 i=2を考えてみる
  // 2: (1,3)(2,)(3,)(4,)(5,7), 3: (1,3,5)(2,4,6)(3,5,7) 4: (1,3,5,7)
  // 2: 7-2 = 5  ,   3: 7-(2*2) = 3  4: 7-(2*3)=1 

  // 差分をdivとして
  // 個数をelcnt とすれば
  // n-(div * (elcnt-1)) while it is positive となる

  // n=4 
  // div = 2
  // 2: (1,3)(2,4)
  // div=1
  // 2: (1,2)(2,3)(3,4) 3:(1,2,3)(2,3,4) 4: (1,2,3,4)
  // これでおわりじゃなかった
  // 追加して、混ざるパターン
  // 3: (1,2,4)(1,3,4)
  // elcnt >2 の場合、3つめ以降は好きな数字を選べる
  // n-(div-1)(elcnt-1)C(elcnt) がこたえ
  // 上の例だと n=4, div=1, elcnt=3
  // (4-(0)(2)C(3)) = 4


  for (int div=1;div<=n;div++) {
    ll plus=0;
    for (int elcnt=1;elcnt<=n;elcnt++) {
      plus += nCrMod(n-((div-1)*(elcnt-1)), elcnt, MODULE);
      plus %= MODULE;
    }
    cout << plus << endl;
  }

  return 0;
}
