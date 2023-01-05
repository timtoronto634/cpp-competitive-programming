#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class SegTree029 {
  ll tree[1000005];
  int num_element;
  public:

  SegTree029(int n) {
    num_element = n;
    for (int i=0;i<2*n;i++) {
      tree[i] = 0;
    }
  }

  int parentIdx(int node) {
    if (node == 0) return node;
    return (node - 1) /2;
  }

  void _updateMax(int node, ll value) {
    if (tree[node] < value) {
      tree[node] = value;
      if (node!=0) _updateMax(parentIdx(node), value);
    }
  }

  ll pile(ll left, ll right) {
    ll mx = rangeMax(left, right+1);
    _updateRangeMax(left, right+1, 0, 0,num_element, mx+1);
    return mx+1;

  }

  // 
  void _updateRangeMax(int left, int right, int node, int cur_l, int cur_r, ll value) {
    if (left == cur_l && right == cur_r) {
      _updateMax(node, value);
      return ;
    }
    int leftEnd = cur_l + (cur_r-cur_l)/2;
    if (left<leftEnd) {
      _updateRangeMax(left,min(right, leftEnd), node*2+1,  cur_l, leftEnd, value);
    }
    if (leftEnd <= right) {
      _updateRangeMax(max(left, leftEnd), right, node*2+1, leftEnd, cur_r, value);
    }

  }

  // return max value of [left, right)
  ll rangeMax(int left, int right) {
    return _rangeMax(left, right+1, 0, 0, num_element);
  }

  ll _rangeMax(int left, int right, int node, int cur_l, int cur_r) {
    if (left > right || right <= left) return 0;
    if (left == cur_l && right == cur_r) {
      return tree[node];
    }
    ll leftMax = _rangeMax(left, min(cur_l + (cur_r-cur_l)/2, right), node*2+1, cur_l, cur_l + (cur_r-cur_l)/2);
    ll rightMax = _rangeMax(max(left, cur_l + (cur_r-cur_l)/2), right, node*2+1, cur_l + (cur_r-cur_l)/2, cur_r);
    return max(leftMax, rightMax);
  }
};

int main() {
  ll W, N, L, R;
  cin >> W >> N;
  SegTree029 segtree = SegTree029(W);
  for (int i=0;i<N;i++) {
    cin >> L >> R;
    ll out = segtree.pile(L, R);
    cout << out << endl;
  }

  return 0;
}
