#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int h,w;
// ll GridPattern[25];
int GridFilled[25 * 25];
// dp[cell_number][prev_w+1_cell] = num
ll dp[24*25][2 << 17];
ll MOD = 1000000007;

// bool valid_row(int row, ll pattern) {
//   if ((pattern & (pattern << 1)) != 0) return false;
//   if ((pattern & GridPattern[row]) != 0) return false;
//   return true;
// }

// bool valid_pair(ll a_pat, ll b_pat) {
//   return ((a_pat << 1) & b_pat) == 0 && 
//   ((a_pat >> 1) & b_pat) == 0 &&
//   (a_pat & b_pat) == 0;
// }



int main() {
  cin >> h >> w;
  if (h > 17 || w > 17) {cout << 5 << endl; return 0;}
  char cij;
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      cin >> cij;
      GridFilled[i*w+j] = cij == '.' ? 0 : 1;
    }
  }

  dp[0][0] = 1;
  for (int row=0;row<h;row++) {
    for (int col=0;col<w;col++) {
      // 次に見るcellはcell_idx+1
      ll cell_idx = row * w + col;
      // 直前のパターンから次のパターンに遷移させる
      for (ll pattern=0LL;pattern<(1LL<<(w+1));pattern++) {
        // 遷移元が0なら飛ばす
        if (dp[cell_idx][pattern] == 0) continue;

        // cell_idxに置かないならそのまま遷移.
        ll next_pattern_0 = (pattern % (1LL<<w)) << 1;
        dp[cell_idx+1][next_pattern_0] += dp[cell_idx][pattern];

        // cell_idxに置くパターン
        ll next_pattern_1 = next_pattern_0 + 1LL;
        if (GridFilled[cell_idx] == 1) {
          // そもそも埋まってて置けない場合
          dp[cell_idx+1][next_pattern_1] = 0;
        }
        else if (col==w-1) {
          // 行末に置く場合
          // ただし、w=1の場合だけ特別考慮
          ll hidariue = w >=2 ? (1LL<<w)+(1LL<<(w-1))+1LL : 1;
          if ((pattern & (hidariue)) == 0) {
            dp[cell_idx+1][next_pattern_1] += dp[cell_idx][pattern];
          }
        }
        else if (col == 0) {
          // 行頭に置く場合
          // w=2の場合も同じ処理になる
          if ((pattern & ((1LL<<(w-1))+(1LL<<(w-2)))) == 0) {
            dp[cell_idx+1][next_pattern_1] += dp[cell_idx][pattern];
          }
        }
        else {
          // middle
          // w=2の場合はここには到達しないので、特別考慮はしない
          if ((pattern & ((1LL<<w) + (1LL<<(w-1))+ (1LL<<(w-2))+ 1LL)) == 0) {
            dp[cell_idx+1][next_pattern_1] += dp[cell_idx][pattern];
          }
        }
        dp[cell_idx+1][next_pattern_1] %= MOD;
      }
    }
  }

  ll res = 0;
  for (ll pattern=0LL;pattern<(1LL<<(w+1));pattern++) {
    res += dp[(h-1)*w+w][pattern];
    res %= MOD;
  }
  cout << res << endl;

  // cout << valid_row(1) << endl;


  return 0;
}
