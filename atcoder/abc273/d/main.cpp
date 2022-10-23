#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
  int h,w,n,r,c,Q;
  map<int, vector<int>> rmap, cmap;
  cin >> h >> w >> r >> c >> n;
  for (int i=0;i<n;i++) {
    int ri, ci;
    cin >> ri >> ci;
    rmap[ri].push_back(ci);
    cmap[ci].push_back(ri);
  }
  for (auto &rv: rmap) {
    rv.second.push_back(0);
    rv.second.push_back(w+1);
    sort(rv.second.begin(), rv.second.end());
  }
  for (auto &cv: cmap) {
    cv.second.push_back(0);
    cv.second.push_back(h+1);
    sort(cv.second.begin(), cv.second.end());
  }

  cin >> Q;
  char d;
  int l;
  for (int i=0; i<Q;i++) {
    cin >> d >> l;
    if (d == 'U') {
      auto el = cmap.find(c);
      int lb = 0;
      if (el != cmap.end()) {
        vector<int> &vec = el->second;
        auto curidx = lower_bound(vec.begin(), vec.end(), r);
        if (curidx != vec.begin()) curidx--;
        lb = (*curidx);
      }
      r = max(lb+1, r-l);
    }
    if (d == 'D') {
      auto el = cmap.find(c);
      int ub = h+1;
      if (el != cmap.end()) {
        vector<int> &vec = el->second;
        auto curidx = upper_bound(vec.begin(), vec.end(), r);
        ub = (*curidx);
      }
      r = min(ub-1, r+l);
    }
    if (d == 'L') {
      auto el = rmap.find(r);
      int lb = 0;
      if (el != rmap.end()) {
        vector<int> &vec = el->second;
        auto curidx = lower_bound(vec.begin(), vec.end(), c);
        if (curidx != vec.begin()) curidx--;
        lb = (*curidx);
      }
      c = max(lb+1, c-l);
    }
    if (d == 'R') {
      auto el = rmap.find(r);
      int ub = w+1;
      if (el != rmap.end()) {
        vector<int> &vec = el->second;
        auto curidx = upper_bound(vec.begin(), vec.end(), c);
        ub = (*curidx);
      }
      c = min(ub-1, c+l);
    }
    cout << r << " " << c << endl;
  }
  return 0;
}