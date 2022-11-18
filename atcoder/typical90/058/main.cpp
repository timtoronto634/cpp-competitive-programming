#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int button1(int n) {
  int y = 0;
  while (n > 0) {
    y += n % 10;
    n /= 10;
  }
  return y;
}

const int MOD=pow(10,5);

int button(int x){
  int y = button1(x);
  return (x+y) % MOD;
}

int main() {
  ll order[1000000];
  ll n, k;
  cin >> n >> k;
  ll i=0;
  // value n after button clicked i time
  while (order[n] == 0 && i<k) {
    order[n] = i;
    n = button(n);
    i++;
  }
  if (i==k) {
    // n is the value after button clicked k time
    cout << n << endl;
    return 0;
  }
  // order[n] is the button last time n encountered, i is this time
  // if button clicked freq time more, then the value is n again
  ll freq = order[n] - i;
  ll restb = (k - order[n]) % freq;
  for (int j=0;j<restb;j++) {
    n = button(n);
  }
  cout << n << endl;
  
  return 0;
}
