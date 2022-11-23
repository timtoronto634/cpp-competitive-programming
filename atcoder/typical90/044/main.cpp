#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> av(n);
  int ai;
  for (int i=0;i<n;i++) {
    cin >> ai;
    av[i] = ai;
  }
  int ti, xi, yi;
  int cur = 0;
  for (int i=0;i<q;i++) {
    cin >> ti >> xi >> yi;
    if (ti == 1) {
      // swap(av[xi-1], av[yi-1]);
      int tmp = av[(yi-1+n-cur)%n];
      av[(yi-1+n-cur)%n] = av[(xi-1+n-cur)%n];
      av[(xi-1+n-cur)%n] = tmp;
    }
    if (ti == 2) {
      cur++;
      cur %= n;
    }
    if (ti == 3) {
      cout << av[(xi-1+n-cur) % n] << endl;
    }
  }
  return 0;
}
