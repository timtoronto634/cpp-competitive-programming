#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, k;
  cin >> n >> k;
  k = min(n, k);
  for (int i=0;i<n;i++) {
    int ai;
    cin >> ai;
    if (i <k) continue;
    cout << ai << " ";
  }
  for (int i=0;i<k;i++) {
    cout << "0 ";
  }
  cout << endl;
  return 0;
}
