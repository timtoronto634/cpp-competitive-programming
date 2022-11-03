#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  string ss = "0123456789ABCDEF";
  if (n < 16) {
    cout << "0" << ss[n] << endl;
  } else {
    cout << ss[n / 16] << ss[n % 16] << endl;
  }
    return 0;
}
