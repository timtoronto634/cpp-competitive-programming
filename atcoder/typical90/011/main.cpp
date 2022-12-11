#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll n, di, ci;
  ll si;
  cin >> n;
  vector<ll> d(n), c(n);
  vector<ll> s(n);
  vector<tuple<ll, ll, ll>> end_cont_rew;
  for (ll i=0;i<n;i++) {
    cin >> di >> ci >> si;
    end_cont_rew.push_back(make_tuple(di, ci, si));
  }
  sort(end_cont_rew.begin(), end_cont_rew.end(), [](auto const &a, auto const &b){
    return get<0>(a) < get<0>(b);
  });
  ll max_reward = 0;
  for (ll bs=1;bs<(1<<n);bs++) {
    ll cur_day = 0; ll cur_reward = 0;
    bool valid = true;

    for (ll work=0;work<n;work++) {
      // その仕事をするか
      if ((bs & (1<<work)) == 0) continue;
      // 締め切りに間に合っているか
      if ((cur_day + get<1>(end_cont_rew[work])) > get<0>(end_cont_rew[work])) {
        valid = false;
        break;
      }
      cur_reward += get<2>(end_cont_rew[work]);
      cur_day += get<1>(end_cont_rew[work]);
    }
    if (valid) max_reward = max(max_reward, cur_reward);
  }
  cout << max_reward << endl;

  return 0;
}
