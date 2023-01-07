#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class segment_tree {
  private:
    int sz;
    std::vector<int> seg;
    std::vector<int> lazy;
    void push(int node) {
      if (node < sz) {
        lazy[node * 2] = max(lazy[node*2], lazy[node]);
        lazy[node * 2 + 1] = max(lazy[node*2 + 1], lazy[node]);
      }
      seg[node] = max(seg[node], lazy[node]);
      lazy[node] = 0;
    }
    void update(int a, int b, int x, int k, int l, int r) {
      push(k);
      if (r <= a || b <= l) return ;
      if (a <= l && r <= b) {
        lazy[k] = x;
        push(k);
        return;
      }
      update(a, b, x, k * 2, l, (l+r) >> 1);
      update(a, b, x, k * 2 + 1, (l+r) >> 1, r);
      seg[k] = max(seg[k * 2], seg[k*2 + 1]);
    }
    int range_max(int a, int b, int node, int l, int r) {
      push(node);
      if (r <= a || b <= l) return 0;
      if (a <= l && r <= b) return seg[node];
      int lc = range_max(a, b, node*2, l, (l+r)>>1);
      int rc = range_max(a, b, node*2+1, (l+r)>>1, r);
      return max(lc, rc);
    }

  public:
    segment_tree() : sz(0), seg(), lazy() {};
    segment_tree(int N) {
      sz = 1;
      while (sz < N) {
        sz *= 2;
      }
      seg = std::vector<int>(sz * 2, 0);
      lazy = std::vector<int>(sz * 2, 0);
    }
    void update(int l, int r, int x) {
      update(l, r, x, 1, 0, sz);
    }
    int range_max(int l, int r) {
      return range_max(l, r, 1, 0, sz);
    }
};

int main() {
  ll W, N, L, R;
  cin >> W >> N;
  segment_tree seg(W);
  for (int i=0; i < N;i++) {
    cin >> L >> R;
    int height = seg.range_max(L-1, R) + 1;
    seg.update(L-1, R, height);
    cout << height << endl;
  }

}
