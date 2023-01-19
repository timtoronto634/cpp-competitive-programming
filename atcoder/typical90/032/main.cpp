#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<vector<int>> times(10, vector<int>(10,0));

int dfs(int kukan, int ppl, vector<vector<int>>& times, vector<int> &done, unordered_map<int, vector<int>>& dislikes) {
  done[ppl]=1;
  if (accumulate(done.begin(), done.end(),0) == done.size()) { done[ppl]=0; return times[ppl][kukan];}
  int n= done.size();
  int mintime=INT_MAX;
  for (int p=0;p<n;p++) {
    if (done[p]==1) continue;
    if (find(dislikes[ppl].begin(), dislikes[ppl].end(), p) != dislikes[ppl].end()) continue;
    int time = dfs(kukan+1, p, times, done, dislikes);
    if (time == -1) continue;
    mintime = min(mintime, time);
  }
  done[ppl]=0;
  if (mintime == INT_MAX) return -1;
  return mintime+times[ppl][kukan];
}

int main() {
  int n, m;
  int aij, xi, yi;
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> aij;
      times[i][j] = aij;
    }
  }
  cin >> m;
  unordered_map<int, vector<int>> dislikes;
  for (int i=0;i<m;i++) {
    cin >> xi >> yi;
    xi--;
    yi--;
    dislikes[xi].push_back(yi);
    dislikes[yi].push_back(xi);
  }

  vector<int> done(n,0);
  int mintime=INT_MAX;
  for (int p=0;p<n;p++) {
    int time =  dfs(0, p, times, done, dislikes);
    if (time == -1) continue;
    mintime = min(mintime, time);
  }
  
  cout <<  (mintime == INT_MAX ? -1 : mintime) << endl;
}
