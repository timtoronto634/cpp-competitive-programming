#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool findArrWithTargetSum(vector<int>& av, int curSum, int targetSum) {
  if (curSum < targetSum) return false;
  if (curSum == targetSum) return true;
  int idx = 0;
  vector<int> idxVal;
  // vector<int> sidx(0);
  // vector<int> sval(0);

  
  while (idx < av.size()) {
    while (curSum > targetSum) {
      curSum -= 2 * av[idx];
      av[idx] *= -1;
      idxVal.push_back(idx);
      idx++;
    }
    if (curSum == targetSum) return true;

    auto p = idxVal[idxVal.size()-1];
    curSum -= 2 * av[p];
    av[p] *= -1;
    idxVal.pop_back();

    if(idxVal.empty()) break;
    auto pp = idxVal[idxVal.size()-1];
    curSum -= 2 * av[pp];
    av[pp] *= -1;
    idxVal.pop_back();
    idx = pp + 1;
    while (idx<av.size() && av[idx-1] == av[idx]) idx++;
  }
  return false;
}



int main() {
  int n, x, y, ai;
  cin >> n >> x >> y >> ai;
  int diffx = (x - ai), diffy = y;
  vector<int> ax(0,0), ay(0,0);
  for (int i=0; i<n-1;i++) {
    cin >> ai;
    if (i & 1) {
      ax.push_back(ai);
    } else {
      // ループ初回はA2でy方向
      ay.push_back(ai);
    }
  }
  sort(ax.begin(),ax.end());
  sort(ay.begin(),ay.end());
  int curSumX = accumulate(ax.begin(), ax.end(), 0);
  int curSumY = accumulate(ay.begin(), ay.end(), 0);
  if (findArrWithTargetSum(ax,curSumX,diffx) && findArrWithTargetSum(ay,curSumY,diffy)) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
