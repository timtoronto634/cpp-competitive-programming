#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  string s;
  cin >> n;
  set<string> registered;
  for (int i=1;i<=n;i++) {
    cin >> s;
    if (registered.count(s)==0) {
      cout << i << endl;
    }
    registered.insert(s);
  }
  return 0;
}
