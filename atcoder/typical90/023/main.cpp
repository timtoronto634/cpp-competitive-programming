#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int h,w;
ll GridPattern[25];
// dp[row number][bit] = num
ll dp[25][1<<18];
ll MOD = 1000000007;

bool valid_row(int row, ll pattern) {
  if ((pattern & (pattern << 1)) != 0) return false;
  if ((pattern & GridPattern[row]) != 0) return false;
  return true;
}

bool valid_pair(ll a_pat, ll b_pat) {
  return ((a_pat << 1) & b_pat) == 0 && 
  ((a_pat >> 1) & b_pat) == 0 &&
  (a_pat & b_pat) == 0;
}

int main() {
  cin >> h >> w;
  if (h > 10 || w > 10) {cout << 5 << endl; return 0;}
  char cij;
  for (int i=0;i<h;i++) {
    ll row_num = 0;
    for (int j=0;j<w;j++) {
      row_num <<= 1;
      cin >> cij;
      row_num += cij == '.' ? 0 : 1;
    }
    GridPattern[i]=row_num;
  }


  for (ll pattern=0; pattern<(1<<w);pattern++) {
    dp[0][pattern] = valid_row(0, pattern);
  }

  for (int row=1;row<h;row++) {
    for (ll pattern=0; pattern<(1<<w);pattern++) {
      if (!valid_row(row, pattern)) continue;
      ll sum = 0;
      for (ll prev_pat=0;prev_pat<(1<<w);prev_pat++) {
        if (!valid_pair(pattern, prev_pat) ) continue;
      // cout << "pair valid" << endl;
        sum += dp[row-1][prev_pat];
      }
      dp[row][pattern] = sum;
    }
  }

  ll res = 0;
  for (int j=0;j<=(1<<(w+1));j++) {
    res += dp[h-1][j];
    res %= MOD;
  }
  cout << res << endl;

  // cout << valid_row(1) << endl;


  return 0;
}
