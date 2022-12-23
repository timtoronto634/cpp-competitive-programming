#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int parent[4040010];

int root(int cur) {
  while (parent[cur] != -1 && parent[cur] != cur) {
    cur = parent[cur];
  }
  return parent[cur];
}

int onlyFind(int cur) {
  while (parent[cur] != -1 && parent[cur] != cur) {
    cur = parent[cur];
  }
  return parent[cur];
}

int main() {
  int h, w, q, t, rai, cai, rbi, cbi;
  cin >> h >> w >> q;

  // union find
  for (int i=0;i<4040010;i++) {
    parent[i] = -1;
  }

  for (int i=0;i<q;i++) {
    cin >> t;
    if (t == 1) {
      cin >> rai >> cai;
      int tar = parent[rai*w+cai];
      if (tar != -1) continue;
      int top = -1;
      if (cai > 1 && parent[rai*w+cai-1] != -1) {
        top = root(rai*w+cai-1);
      }
      if (cai < w && parent[rai*w+cai+1] != -1) {
        if (top == -1) top = root(rai*w+cai+1);
        else parent[root(rai*w+cai+1)] = top;
      }
      if (rai > 1 && parent[(rai-1)*w+cai] != -1) {
        if (top == -1) top = root((rai-1)*w+cai);
        else parent[root((rai-1)*w+cai)] = top;
      }
      if (rai < h && parent[(rai+1)*w+cai] != -1) {
        if (top == -1) top = root((rai+1)*w+cai);
        else parent[root((rai+1)*w+cai)] = top;
      }
      // if no union, then set cur and increment cur;
      if (top == -1) top = rai*w+cai;
      parent[rai*w+cai] = top;
    }
    else {
      cin >> rai >> cai >> rbi >> cbi;
      bool same = (root(rai*w+cai)!=-1) && (root(rbi*w+cbi)!=-1) && (root(rai*w+cai) == root(rbi*w+cbi));
      cout << (same ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
