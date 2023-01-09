#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int mex(int gnum) {
  return gnum == 0 ? 1 : 0;
}

int mex(vector<int> gvec) {
  vector<int> used(gvec.size()+1,0);
  for (int gnum : gvec) {
    if (gnum < 0 || gnum > gvec.size()) continue;
    used[gnum]++;
  }
  for (int i=0;i<gvec.size()+1;i++) {
    if (used[i] == 0) return i;
  }
  // cout << "ERROR" << endl;
  return 0;// not used
}

int op1(int dp[][1400], int w, int b) {
  if (w == 0) return -1;
  return dp[w-1][b+w];
}

void op2(int dp[][1400], int w, int b, vector<int> &arr) {
  if (b < 2) return;
  for (int i=1;i<=(b/2);i++) {
    arr.push_back(dp[w][b-i]);
  }
  return;
}

int groundy_dp[51][1400]; // white, blue
int main() {
  int N, W, B;
  cin >> N;
  groundy_dp[0][1] = 0;
  for (int w=0;w<=50;w++) {
    for (int b=0; b<1400;b++) {
      vector<int> arr;
      op2(groundy_dp, w, b, arr);
      if (w!=0) {
        arr.push_back(op1(groundy_dp, w, b));
      } 
      groundy_dp[w][b] = mex(arr);
    }
  }
  int xor_res = 0;
  vector<int> ws(N), bs(N);
  for (int i=0;i<N;i++) cin >> ws[i];
  for (int i=0;i<N;i++) cin >> bs[i];
  for (int i=0;i<N;i++) {
    xor_res ^= groundy_dp[ws[i]][bs[i]];
  }
  cout << (xor_res == 0 ? "Second" : "First") << endl;
  return 0;
}
