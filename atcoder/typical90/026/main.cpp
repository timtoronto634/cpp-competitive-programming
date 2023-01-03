#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int color[200000];
int num1;

void dfs(int node, map<int,vector<int>>& tree, bool flag) {
  if (color[node] != 0) return;
  color[node] = flag? 1 : -1;
  if (flag) num1++;

  for (int nod : tree[node]) {
    dfs(nod, tree, !flag);
  }
}

int main() {
  int n,ai,bi;
  cin >> n;
  map<int,vector<int>> tree;

  for (int i=1;i<n;i++) {
    cin >> ai >> bi;
    tree[ai].push_back(bi);
    tree[bi].push_back(ai);
  }
  dfs(1, tree, true);
  int cnt = 0;
  int idx = 0;
  int target = num1 >= (n/2) ? 1 : -1;
  while (cnt < n /2) {
    idx++;
    if (color[idx]==target) {
      if (cnt != 0) cout << " ";
      cout << idx;
      cnt++;
    }
  }
  cout << endl;



  return 0;
}
