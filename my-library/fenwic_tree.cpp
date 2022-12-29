#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class BIT {
  public:
    int size_ = 1;
    vector<ll> bit;

    void init(int sz) {
      size_ = sz + 2;
      bit.resize(size_ + 2, 0);
    }

    ll get(int i) {
      return bit[i];
    }

    void add(int pos, ll value) {
      pos++;
      while (pos <= size_) {
        bit[pos] += value;
        pos = pos + (pos & -pos);
      }
    }

    ll sum(int pos) {
      ll sum_ = 0;
      pos++;
      while (pos >= 1) {
        sum_ += bit[pos];
        pos -= (pos & -pos);
      }
      return sum_;
    }

    ll sumRange(int from, int to) {
      to++;
      return sum(to) - sum(from);
    }
};

void check(int expected, int actual) {
  cout << "expected: " << expected;
  cout << ", actual: " << actual;
  cout << endl;
}

// void Init(int arr[]) {
//   for (int i=0;i<5;i++) {
//     arr[i] = i;
//   }
// }

// void Show(int arr[]) {
//   for (int i=0;i<5;i++) {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
//       int size = sizeof(arr)/sizeof(arr[0]);
//       cout << "size: " << size << endl;
// }

int main() {
  int test[5] = {1,2,3,4,5};

  BIT tree;
  tree.init(5);
  for (int i=0;i<5;i++) tree.add(i, test[i]);

  check(1, tree.sum(0));
  check(3, tree.sum(1));
  check(6, tree.sum(2));
  check(10, tree.sum(3));
  check(15, tree.sum(4));
}