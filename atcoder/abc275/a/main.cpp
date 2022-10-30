#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
    int m = 0, idx = 0;
  for (int i=1;i<=n;i++) {
    int ci;
    cin >> ci;
    if (m < ci) {
      m = ci;
      idx = i;
    }
  }
  cout << idx << endl;
  return 0;
}
