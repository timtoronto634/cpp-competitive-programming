#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    int n;
  cin >> n;
  vector<ll> mangas;
  set<int> seen;
  int yuuyo = 0;
  for (int i=0;i<n;i++){
    ll ai;
    cin >> ai;
    if (seen.count(ai) > 0 || ai > n) {
      yuuyo++;
      continue;
    }
    mangas.push_back(ai);
    seen.insert(ai);
  }
  sort(mangas.begin(), mangas.end());
  int left = 0, right = mangas.size();
  int kan = 0;
  while (left<right || yuuyo>1) {
    if (mangas[left] == (kan+1)) {
      left++;
      kan++;
      continue;
    }
    if (yuuyo>1) {
      yuuyo -= 2;
      kan++;
      continue;
    }

    if (yuuyo==1) {
      yuuyo=0;
      right -= 1;
    } else {
      right -= 2;
    }
    if (left<=right) {
      kan++;
    }
  }
  cout << kan << endl;
    return 0;
}
