#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n,l;
  cin >> n >> l;
  int k;
  cin >> k;
  vector<int> divs(n);
  int left = l, right = l;
  for(int i=0;i<n;i++) {
    cin >> divs[i];
    left = min(left, divs[i]);
  }

  // is the answer over x?
  int mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    // whether x can be 
    bool isMidValid = true;

    ll curSum = 0;
    int cnt = 0;
    for (int i=0;i<n;i++) {
      curSum += divs[i];
      if (curSum > mid) {
        curSum = 0;
        cnt++;
      }
      if (cnt > k) {
        isMidValid = false;
        break;
      }
    }

    if (isMidValid) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}
