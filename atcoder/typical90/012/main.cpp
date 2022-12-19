#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int parent[4040010];

int findPar(int cur) {
  if (parent[cur] == -1) {
    parent[cur] = cur;
  } else if (parent[cur] != cur) {
    parent[cur] = findPar(parent[cur]);
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
      int tar = parent[rai*h+cai];
      if (tar != -1) continue;
      int top = -1;
      if (cai > 0 && parent[rai*h+cai-1] != -1) {
        top = findPar(rai*h+cai-1);
      }
      if (cai < w-1 && parent[rai*h+cai+1] != -1) {
        if (top == -1) top = findPar(rai*h+cai+1);
        else parent[findPar(rai*h+cai+1)] = top;
      }
      if (rai > 0 && parent[(rai-1)*h+cai] != -1) {
        if (top == -1) top = findPar((rai-1)*h+cai);
        else parent[findPar((rai-1)*h+cai)] = top;
      }
      if (rai < (h-1) && parent[(rai+1)*h+cai] != -1) {
        if (top == -1) top = findPar((rai+1)*h+cai);
        else parent[findPar((rai+1)*h+cai)] = top;
      }
      // if no union, then set cur and increment cur;
      if (top == -1) top = rai*h+cai;
      parent[rai*h+cai] = top;
    }
    else {
      cin >> rai >> cai >> rbi >> cbi;
      if (rai == 4 && cai == 2 && rbi == 3) {
        for (int i=1;i<=h;i++) {
          for (int j=1;j<=w;j++) {
            cout << parent[i*h+j];
          }
          cout << endl;
        }
      }
      bool same = (onlyFind(rai*h+cai)!=-1) && (onlyFind(rbi*h+cbi)!=-1) && (findPar(rai*h+cai) == findPar(rbi*h+cbi));
      cout << (same ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
