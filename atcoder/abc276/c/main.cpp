#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  vector<int> vv(n);
  for (int i=0;i<n;i++) {
    cin >> vv[i];
  }
  int cur = vv[n-1]+1;
  vector<int> found;
  int last ;
  int i;
  for (i=n-1;i>=0;i--) {
    if (vv[i] < cur) {
      found.push_back(vv[i]);
      cur = vv[i];
    } else {
      last = vv[i];
      break;
    }
  }
  sort(found.begin(), found.end());
  auto nhead = lower_bound(found.begin(), found.end(), last);
  nhead--;
  // if (nhead == found.end()) {

  // }
  int head = *nhead;
  found.erase(nhead);
  found.push_back(last);
  sort(found.begin(), found.end());
  for (int o=0;o<i;o++) {
      cout << vv[o] << " ";
    }
  
      cout << head << " ";
  for (int o=found.size()-1;o>=0;o--){
      cout << found[o] << " ";
    }

  cout << endl; 
  
  return 0;
}
