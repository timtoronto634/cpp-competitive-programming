#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<vector<long long> > vvll, vvLL;


template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

int main() {
  const ll INF = 1LL << 60;
  ll n, x;
  cin >> n >> x;
  vector<pair<ll,ll>> ps;
  ps.emplace_back(0, 2*n);
  ps.emplace_back(x, 2*n + 1);
  ps.emplace_back(-INF, 2*n + 2);
  ps.emplace_back(INF, 2*n + 2);

  vector<ll> ys(n), zs(n);
  for (int i=0;i<n;i++) cin >> ys[i];
  for (int i=0;i<n;i++) cin >> zs[i];

  for (int i=0;i<n;i++) {
    ps.emplace_back(ys[i], i);
    ps.emplace_back(zs[i], i+n);
  }

  sort(ps.begin(), ps.end());
  int sz = ps.size();

  int start = lower_bound(ps.begin(), ps.end(), pair<ll,ll>(0, 2*n)) - ps.begin();
  int goal = lower_bound(ps.begin(), ps.end(), pair<ll,ll>(x, 2*n + 1)) - ps.begin();

  vvll ds[2];
  initvv(ds[0], sz, sz, INF);
  initvv(ds[1], sz, sz, INF);
  ds[0][start][start] = 0;
  priority_queue<tuple<ll, int,int,int>> pq;
  pq.emplace(0,0,start,start);

  while(!pq.empty()){
    ll tm;
    int sd, l, r;
    tie(tm, sd, l, r) = pq.top();
    pq.pop();
    tm = -tm;

    if (l <= goal && goal <= r) {
      cout << tm << "\n";
      return 0;
    }

    for (int nsd=0; nsd < 2; ++nsd) {
      int nl, nr, np;
      if (nsd == 0) {
        nl = np = l - 1;
        nr = r;
      }
      else {
        nl = l;
        nr = np = r + 1;
      }

      int id = ps[np].second;
      if (id == 2 * n + 2) {continue;}
      if (id < n) {
        if (zs[id] < ps[l].first || ps[r].first < zs[id]) continue;
      }

      ll ntm = tm + abs(ps[np].first - ps[sd ? r : l].first);
      if (ds[nsd][nl][nr] > ntm) {
        ds[nsd][nl][nr] = ntm;
        pq.emplace(-ntm, nsd, nl,nr);
      }
    }
  }
  cout << "-1\n";

  
}
