#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  ll prime;
  vector<vector<int>> cnts;
  for (int i=0;i<n;i++) {
    int two = 0;
    int thr = 0;
    ll ai;
    cin >> ai;

    // bool candiv3;
    // string strai = to_string(ai);
    // int ketasum = 0;
    // for (int si=0;si<strai.size();si++) {
    //   ketasum += int(strai[si]-'0');
    // }
    // candiv3 = (ketasum % 3 == 0);

    while (!(ai & 1)) {
      ai >>= 1;
      two++;
    }

    while (ai % 3 == 0) {
      ai /= 3;
      thr++;
    }
    if (i==0) {
      prime = ai;
    } else {
      if (ai != prime) {
        cout << -1 << endl;
        return 0;
      }
    }
    cnts.push_back(vector<int>{two, thr});
  }
  int mintwo=INT_MAX, minthr=INT_MAX;
  for (int i=0;i<n;i++) {
    mintwo = min(cnts[i][0], mintwo);
    minthr = min(cnts[i][1], minthr);
  }
  int ans = 0;
  for (int i=0;i<n;i++) {
    ans += cnts[i][0] - mintwo;
    ans += cnts[i][1] - minthr;
  }
  cout << ans << endl;

  return 0;
}
