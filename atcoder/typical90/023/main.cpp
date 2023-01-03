#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int h,w;
int GridFilled[25 * 25];
const int NumPattern = 500000;

// dp[cell_number][prev_w+1_cell] = num
ll dp[24*25][NumPattern];
const ll MOD = 1000000007;

bool valid(ll pattern, int width) {
  int consecutive = 0;
  int num_cons = 0;
  if (((pattern >> width) & pattern)==1) return false;
  while (pattern > 0) {
    if (pattern & 1) {
      consecutive++;
      if (consecutive == 2) {
        num_cons++;
        if (num_cons == 2) {
          return false;
        }
      }
      else if (consecutive == 3) {
        return false;
      }
    } else {
      consecutive = 0;
    }
    pattern >>= 1;
  }
  return true;
}

int main() {
  cin >> h >> w;
  char cij;
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      cin >> cij;
      GridFilled[i*w+j] = cij == '.' ? 0 : 1;
    }
  }
  // valid patterns
  ll idx2pattern[NumPattern];
  map<ll,ll> pattern2idx;
  ll num_pattern = 0;
  for (ll pattern=0LL;pattern<(1LL<<(w+1));pattern++) {
    if (valid(pattern, w)) {
      // if (num_pattern > 500000) {
      //   num_pattern++;
      //   continue;
      // }
      idx2pattern[num_pattern] = pattern;
      pattern2idx[pattern] = num_pattern;
      num_pattern++;
    }
  }
      // if (num_pattern > 500000) {
      //   cout << num_pattern << endl;
      //   return 0;
      // }
  dp[0][0] = 1;
  for (int row=0;row<h;row++) {
    for (int col=0;col<w;col++) {
      // 次に見るcellはcell_idx+1
      ll cell_idx = row * w + col;
      // 直前のパターンから次のパターンに遷移させる
      for (ll pattern_idx=0LL;pattern_idx<num_pattern;pattern_idx++) {
        ll pattern = idx2pattern[pattern_idx];
        // 遷移元が0なら飛ばす
        if (dp[cell_idx][pattern_idx] == 0) continue;

        // cell_idxに置かないならそのまま遷移.
        ll next_pattern_0 = ((pattern % (1LL<<w)) << 1);
        if (pattern2idx.count(next_pattern_0) == 1) {
          dp[cell_idx+1][pattern2idx[next_pattern_0]] += dp[cell_idx][pattern_idx];
        }

        // cell_idxに置くパターン
        ll next_pattern_1 = next_pattern_0 + 1LL;
        if (pattern2idx.count(next_pattern_1) == 0) {
          // このパターンは存在しない
          continue;
        }

        ll next_1_idx = pattern2idx[next_pattern_1];
        if (GridFilled[cell_idx] == 1) {
          // そもそも埋まってて置けない場合
          dp[cell_idx+1][next_1_idx] = 0;
        }
        else if (col==w-1) {
          // 行末に置く場合
          // ただし、w=1の場合だけ特別考慮
          ll hidariue = w >=2 ? (1LL<<w)+(1LL<<(w-1))+1LL : 1;
          if ((pattern & (hidariue)) == 0) {
            dp[cell_idx+1][next_1_idx] += dp[cell_idx][pattern_idx];
          }
        }
        else if (col == 0) {
          // 行頭に置く場合
          // w=2の場合も同じ処理になる
          if ((pattern & ((1LL<<(w-1))+(1LL<<(w-2)))) == 0) {
            dp[cell_idx+1][next_1_idx] += dp[cell_idx][pattern_idx];
          }
        }
        else {
          // middle
          // w=2の場合はここには到達しないので、特別考慮はしない
          if ((pattern & ((1LL<<w) + (1LL<<(w-1))+ (1LL<<(w-2))+ 1LL)) == 0) {
            dp[cell_idx+1][next_1_idx] += dp[cell_idx][pattern_idx];
          }
        }
        dp[cell_idx+1][next_1_idx] %= MOD;
      }
    }
  }

  ll res = 0;
  for (ll pattern_idx=0LL;pattern_idx<(1LL<<(w+1));pattern_idx++) {
    res += dp[(h-1)*w+w][pattern_idx];
    res %= MOD;
  }
  cout << res << endl;

  // cout << valid_row(1) << endl;


  return 0;
}
