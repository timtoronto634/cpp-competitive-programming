#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n, di, ci;
  ll si;
  cin >> n;
  vector<int> d(n), c(n);
  vector<ll> s(n);
  int end_day = 0;
  for (int i=0;i<n;i++) {
    cin >> di >> ci >> si;
    d[i] = di, c[i]=ci, s[i]=si;
    end_day = max(di, end_day);
  }
  int num_days = end_day+1;
  // dp[何日目か][その日について仕事を][終えているか]  = 最大の報酬額
  vector<vector<vector<ll>>> dp(num_days, vector<vector<ll>>(n, vector<ll>(2,0)));
  // best_of_day: その日に出せる最大値。
  ll best_of_day = 0;
  unordered_set<int> last_best_work;
  for (int day=1; day<=end_day; day++) {
    for (int work=0;work<n;work++) {
      // if ()
      if (d[work] > day || day-c[work] < 0) {
        // 既に締め切りが過ぎている場合は、仕事を新しく終えることはできない
        // 必要な日数が経過していない場合も
        dp[day][work][1] = dp[day-1][work][1];
      } else {
        // max(ちょうどその日に仕事を終える場合, 前日までに仕事を終えている場合)
        dp[day][work][1] = max(s[work] + dp[day-c[work]][work][0], dp[day-1][work][1]);
      }
      // 現状最大値がでたなら、保持しておく。
      if (dp[day][work][1] > best_of_day) {
        best_of_day = dp[day][work][1];
        last_best_work = set<int>(work);
      } else if (dp[day][work][1] == best_of_day) {
        last_best_work.insert(work);
      }
      dp[day][work][0] = best_of_day;
    }
  }

  return 0;
}
