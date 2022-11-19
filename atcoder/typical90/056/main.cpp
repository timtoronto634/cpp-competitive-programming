#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n,s;
  cin >> n >> s;
  int ai, bi;
  vector<vector<int>> abs(n);
  for (int i=0;i<n;i++) {
    cin >> ai >> bi;
    abs[i].push_back(ai);
    abs[i].push_back(bi);
  }
  vector<set<int>> prices(n+1);
  prices[0].insert(0);
  for (int i=0;i<n;i++) {
    int num = prices[i].size();
    ai = abs[i][0];
    bi = abs[i][1];
    for (auto cur : prices[i]) {
      if (cur+ai <= s) prices[i+1].insert(cur+ai);
      if (cur+bi <= s) prices[i+1].insert(cur+bi);
    }
    // sort(prices[i+1].begin(), prices[i+1].end());
  }
  string out = "";
  if (prices[n].count(s) == 1) {
    int sum = s;
    for (int j=n-1;j>=0;j--) {
      // for each level, if sum-ai or sum-bi is in lower level, continue looking for it
      if (find(prices[j].begin(), prices[j].end(), sum-abs[j][0]) != prices[j].end() ) {
        out.insert(out.begin(), 'A');
        sum -= abs[j][0];
        continue;
      };
      if (find(prices[j].begin(), prices[j].end(), sum-abs[j][1]) != prices[j].end() ) {
        out.insert(out.begin(), 'B');
        sum -= abs[j][1];
        continue;
      };
    }
    cout << out << endl;
    return 0;
  }
  cout << "Impossible" << endl;

  return 0;
}

