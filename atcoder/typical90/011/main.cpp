#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll dp[5009][5009];
ll d[5009], c[5009], s[5009];

int main() {
  ll n, di, ci;
  ll si;
  cin >> n;

  vector<tuple<ll, ll, ll>> end_cont_rew;
  for (ll i=0;i<n;i++) {
    cin >> di >> ci >> si;
    end_cont_rew.push_back(make_tuple(di, ci, si));
  }
  sort(end_cont_rew.begin(), end_cont_rew.end());
  for (int i=1;i<=n;i++) {
    d[i] = get<0>(end_cont_rew[i-1]);
    c[i] = get<1>(end_cont_rew[i-1]);
    s[i] = get<2>(end_cont_rew[i-1]);
  }

  for (int i=0;i<n;i++) {
    for (int day=0;day<5009;day++) {
      // when not do the work i+1
      dp[i+1][day] = max(dp[i+1][day], dp[i][day]);
      // when do the work i+1
      if (day + c[i+1] <= d[i+1]) {
        dp[i+1][day+c[i+1]] = max(dp[i+1][day+c[i+1]], dp[i][day]+s[i+1]);
      }
    }
  }
  long long Answer = 0;
	for (int i = 0; i <= 5000; i++) Answer = max(Answer, dp[n][i]);
	cout << Answer << endl;

  return 0;
}
