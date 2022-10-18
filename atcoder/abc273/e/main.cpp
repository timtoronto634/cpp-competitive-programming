#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct node {
  node *Next;
  node *Pre;
  int val;
};

int Q, x;
string op;
map<int, node*> notebook;
int main() {
  cin >> Q;
  node root = node{0, 0,-1};
  node* prev = &root;
  vector<int> arr(Q,0);
  for (int i=0; i<Q;i++) {
    cin >> op;
    if (op == "ADD") {
      cin >> x;
      node n = node{0, prev, x};
      (*prev).Next = &n;
      prev = &n;
      arr[i] = x;
    }
    if (op == "SAVE") {
      cin >> x;
      notebook[x] = prev;
      arr[i] = prev->val;
    }
    if (op == "LOAD") {
      cin >> x;
      prev = notebook[x];
      if (prev != 0) {
      arr[i] = prev->val;
      }
    }
    if (op == "DELETE") {
      prev = (*prev).Pre;
      arr[i] = prev->val;
    }
  }
  for (int i=0; i<Q; i++) {
    cout << arr[i];
    if (i != (Q-1)) {
      cout << " ";
    } else {
      cout << endl;
    }
  }

  return 0;
}
