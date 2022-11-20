#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool misleading(int h, int m) {
  int h1 = h / 10, h2 = h %10;
  int m1 = m / 10, m2 = m %10;
  if (h2 >= 6) return false;
  if (m1 <= 3) {
    return true;
  }
  if (h1 == 2 && m1 >= 4) return false;
  return true;
}

int main() {
  int h,m;
  cin >> h >> m;
  while (!misleading(h,m)) {
    m += 1;
    if (m==60) {
      m = 0;
      h += 1;
    }
    if (h==24) {
      h = 0;
    }
  }
  cout << h << " " << m << endl;
  return 0;
}
