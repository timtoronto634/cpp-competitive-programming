#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  vector<int> coins(3);
  cin >> coins[0] >> coins[1] >> coins[2];
  sort(coins.begin(), coins.end(),[](auto const& lhs, auto const& rhs) {
    return lhs > rhs;});
  int curmin = 10000;
  for (int start = n / coins[0]; start >= 0; start--) {
    for (int second = min(9999-start, (n-start*coins[0]) / coins[1]); second >= 0;second--) {
      if ((n- start*coins[0] - second*coins[1]) % coins[2] == 0) {
        curmin = min(curmin, start + second + ((n- start*coins[0] - second*coins[1])/coins[2]));
        break;
      }
    }
  }
        cout << curmin << endl;

  return 0;
}
