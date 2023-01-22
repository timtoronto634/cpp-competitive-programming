#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  ll n, q;
  ll xi, yi;
  vector<vector<ll>> v;
  cin >> n >> q;
  ll X, Y;
  for (ll i=0;i<n;i++) {
    cin >> xi >> yi;
    X = xi-yi;
    Y = xi+yi;
    v.push_back(vector<ll>{X,Y});
  }
  ll maxX, maxY, minX, minY;
  maxX = LONG_MIN;
  maxY = LONG_MIN;
  minX = LONG_MAX;
  minY = LONG_MAX;
  for (ll i=0;i<n;i++) {
    maxX = max(maxX, v[i][0]);
    maxY = max(maxY, v[i][1]);
    minX = min(minX, v[i][0]);
    minY = min(minY, v[i][1]);
  }
  ll stan;
  for (ll i=0;i<q;i++) {
    cin >> stan;
    stan--;
    ll Xi = v[stan][0];
    ll Yi = v[stan][1];
    ll out = max(maxX - Xi, Xi - minX);
    out = max(out,max(maxY - Yi, Yi - minY));
    cout << out << endl;
  }

  return 0;
}
