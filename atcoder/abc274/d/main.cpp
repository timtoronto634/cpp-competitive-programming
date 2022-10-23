#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


bool findArrWith2TargetSum(vector<int> v, int targetSumA, int targetSumB, int targetSum) {
  sort(v.begin(), v.end());
  int thisTarget = min(targetSumA, targetSumB);
  stack<pair<int, int>> idxVal;
  int curSum = 0, idx = 0;
  while (idx < v.size()) {
    while (curSum < targetSumA) {
      curSum += v[idx];
      idxVal.push(make_pair(idx, v[idx]));
      idx++;
    }
    if (curSum == thisTarget) return true;

    if(idxVal.empty()) break;
    auto p = idxVal.top();
    curSum -= p.second;
    idxVal.pop();
    auto pp = idxVal.top();
    idx = pp.first + 1;
    curSum -= pp.second;
  }
  return false;  

}

bool findArrWithTargetSum(vector<int>& av, int curSum, int targetSum, int targetSumA, int targetSumB) {
  int stackSum = 0, idx = 0;
  stack<pair<int, int>> idxVal;
  
  while (idx < av.size()) {
    while (curSum > targetSum) {
      curSum -= 2 * av[idx];
      av[idx] *= -1;
      idxVal.push(make_pair(idx, av[idx]));
      idx++;
    }
    if (curSum == targetSum && findArrWith2TargetSum(av, targetSumA, targetSumB, targetSum)) return true;

    auto p = idxVal.top();
    curSum -= p.second;
    av[p.first] *= -1;
    idxVal.pop();

    if(idxVal.empty()) break;
    auto pp = idxVal.top();
    curSum -= pp.second;
    av[pp.first] *= -1;
    idxVal.pop();
    idx = pp.first + 1;
  }
  return false;
}



int main() {
  int n, x, y, ai;
  cin >> n >> x >> y >> ai;
  int diffx = (x - ai), diffy = y, difftotal = diffx+diffy;
  vector<int> av(n-1,0);
  sort(av.begin(),av.end());
  for (int i=0; i<n-1;i++) {
    int ax;
    cin >> ax;
    av[i] = ax;
  }
  int curSum = accumulate(av.begin(), av.end(), 0);
  if (findArrWithTargetSum(av, curSum, difftotal, diffx, diffy)) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
