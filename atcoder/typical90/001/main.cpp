#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n,l;
  cin >> n >> l;
  int k;
  cin >> k;
  vector<int> divs(n+1);
  int left = 1, right = l;
  int ni;
  int prev=0;
  for(int i=0;i<n;i++) {
    cin >> ni;
    divs[i] = ni - prev;
    prev = ni;
    // left = min(left, divs[i]);
  }
  divs[n] = l - ni;

  // is the answer can be more than x?
  int mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    // whether x can be 
    bool isMidValid = true;

    ll curSum = 0;
    int cnt = 0;
    for (int i=0;i<n+1;i++) {
      curSum += divs[i];
      if (curSum >= mid) {
        curSum = 0;
        cnt++;
      }
      if (cnt > k)      break;
    }

    if (cnt >= k+1) {
      // mid以上のblockがk+1個以上あればそれは答えになりうる。もっと大きな値もありうる
      left = mid+1;
    } else {
      right = mid;
    }
  }
  cout << right-1 << endl;
  return 0;
}
