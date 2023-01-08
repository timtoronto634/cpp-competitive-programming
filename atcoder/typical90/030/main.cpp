#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<int>nums(N+1,0);
  for (int p=2;p<=N;p++) {
    if (nums[p] != 0) continue;
    for (int bai=p; bai<=N;bai+=p) {
      nums[bai]++;
    }
  }
  int ans=0;
  for (int cnt=0;cnt<=N;cnt++) {
    if (nums[cnt] >= K) ans++;
  }
  cout << ans << endl;
  return 0;
}
