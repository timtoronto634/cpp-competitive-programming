#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, q, ci, pi, l, r;
  cin >> n;
  vector<int> class1(n, 0);
  vector<int> class2(n, 0);
  for (int i=0;i<n;i++) {
    cin >> ci >> pi;
    if (ci == 1) {
      class1[i] = pi;
    } else {
      class2[i] = pi;
    }
  }
  vector<int> sum1(n,0), sum2(n,0);
  int cur1 = 0, cur2 = 0;
  for (int i=0;i<n;i++) {
    cur1 += class1[i];
    sum1[i] = cur1;
    cur2 += class2[i];
    sum2[i] = cur2;
  }
  sum1.insert(sum1.begin(), 0);
  sum2.insert(sum2.begin(), 0);
  cin >> q;
  for (int i=0;i<q;i++) {
    cin >> l >> r;
    cout << (sum1[r] - sum1[l-1]) << " ";
    cout << (sum2[r] - sum2[l-1]) << endl;
  }
  return 0;
}
