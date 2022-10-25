#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;

int main() {
  size_t n,m;
  int xi,yi,pi,qi;
  cin >> n >> m;
  vector<ll> vx(n+m), vy(n+m);
  for (int i=0;i<n+m;i++) {
    cin >> vx[i+1] >> vy[i+1];
  }
  vector<vector<ld>> distance(18, vector<ld>(18));
  for (int i=0;i<n+m+1;i++) {
    for (int j=0;j<n+m+1;j++) {
      distance[i][j] = sqrt((vx[i]-vx[j])*(vx[i]-vx[j]) + (vx[i]-vy[j])*(vx[i]-vy[j]));
    }
  }
  vector<map<bitset<18>, int>> dp(n+m+1);


  return 0;
}
