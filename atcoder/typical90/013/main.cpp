#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class asc_pq {
  priority_queue<pair<ll, int>> pq;
  // asc_pq() : 
  public:
    bool empty() {
      return pq.empty();
    }
    void push(ll cost, int city) {
      pq.push(make_pair(-1 * cost, city));
      return;
    }
    int topcity() {
      return pq.top().second;
    }

    ll topcost() {
      return pq.top().first * -1;
    }

    void pop() {
      pq.pop();
      return ;
    }
};

vector<ll> dijkstra(int n, map<int, map<int, ll>>& mp, int start) {
  vector<ll> distance(n, -1);
  asc_pq pq;
  distance[start]=0;

  // ways:  {to: cost}
  for (auto ways : mp[start]) {
    pq.push(ways.second, ways.first);
  }

  while (!pq.empty()) {
    int next_city = pq.topcity();
    ll cost = pq.topcost();
    pq.pop();
    if (distance[next_city] != -1) continue;
    distance[next_city] = cost;

    for (auto ways : mp[next_city]) {
      if (distance[ways.first] != -1) continue;
      pq.push(cost + ways.second, ways.first);
    }
  }

  // for (auto item : distance) {
  //   if (item == -1)cout << "ERROR" << endl;
  // }
  
  
  return distance;
}

int main() {
  ll n, m;
  cin >> n >> m;
  map<int, map<int, ll>> mp;
  // vector<vector<ll>> distance(n, vector<ll>(n));
  ll ai, bi, ci;
  for (int i=0;i<m;i++) {
    cin >> ai >> bi >> ci;
    mp[ai-1][bi-1] = ci;
    mp[bi-1][ai-1] = ci;
  }
  vector<ll> start2mid = dijkstra(n, mp, 0);
  vector<ll> mid2end = dijkstra(n, mp, n-1);

  for (int i=0;i<n;i++) {
    cout << start2mid[i] + mid2end[i] << endl;
  }
  return 0;
}
