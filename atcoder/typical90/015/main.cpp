#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll MODULE = 1000000007;

int main() {
  int n;
  cin >> n;

  vector<ll> ans(n+1);
  ans[n] = n;
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


  for (int div=n-1;div>0;div--) {
    ll plus=0;
    for (int elcnt=2;div*(elcnt-1)<n;elcnt++) {
      plus += (n-(div * (elcnt-1)));
      plus %= MODULE;
    }
    ans[div] = (ans[div+1] + plus) % MODULE;
  }

  for (int i=1;i<=n;i++) cout << ans[i] << endl;

  return 0;
}
