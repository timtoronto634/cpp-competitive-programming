#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long int;
long double PI = 3.14159265358979;

long double t, l,X,Y, e, q;
int main() {
  cin >> t >>  l >> X >> Y >> q;
  cout << setprecision(10);
  for (int i=0;i<q;i++) {
    cin >> e;
    long double y = -(l/ 2.0) * sin(2.0 * PI * e / t) ;
    long double z = (l / 2.00) - ((l/ 2.0) * cos(2.0 * PI * e / t) );
    long double d1 =sqrt(X*X + ((Y-y)*(Y-y)));
    long double angle = atan2(z, d1) * 180.0L / PI;
    cout << setprecision(10) << angle << endl;
  }
  return 0;
}
