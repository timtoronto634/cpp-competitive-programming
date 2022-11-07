#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n , q;
  cin >> n >> q;
  map<int, vector<int>> la;
  int li, ai;
  for (int idx=0;idx<n;idx++) {
    cin >> li;
    for (int j=0;j<li;j++) {
      cin >> ai;
      la[idx].push_back(ai);
    }
  }

  for (int i=0;i<q;i++) {
    int s, t;
    cin >> s >> t;
    cout << la[s-1][t-1] << endl;
  }
    return 0;
}
