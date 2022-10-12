#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int sum;
    sum = 0;
    int a;
    for (int i=0;i<x;i++) {
      cin >> a;
      sum += a;
    }
    cout << sum << endl;
}

int main() {
    solve();
  return 0;
}
