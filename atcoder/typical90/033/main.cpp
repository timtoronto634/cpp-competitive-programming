#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int h,w;
  cin >> h >> w;
  int m;
  if (h==1) {
    m = w;
  } else if (w == 1) {
    m = h;
  } else {
    m = (((h+1)/2) * ((w+1)/2));
  }
  cout << m << endl;
  return 0;
}
