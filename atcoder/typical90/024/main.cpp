#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int A[1000], B[1000];
int main() {
  int n,k;
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  for (int i=0;i<n;i++) {
    cin >> B[i];
  }
  ll diff = 0;
  for (int i=0;i<n;i++) {
    diff += abs(A[i] - B[i]);
  }
  if ((k >= diff) && ((diff - k) % 2 == 0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }



  return 0;
}
