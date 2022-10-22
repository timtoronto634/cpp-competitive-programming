#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class Node {
  public:
    int val;
    Node* prev;
    Node* next;
    Node(int k) {
      val = k;
      prev = nullptr;
      next = nullptr;
    }
};

int main() {
  int Q, x;
  string op;
  cin >> Q;
  Node* root = new Node(-1);
  Node* cur = root;
  map<int, Node*> notebook;
  for (int i=0; i<Q;i++) {
    cin >> op;
    if (op == "ADD") {
      cin >> x;
      Node* n = new Node(x);
      cur->next = n;
      n->prev = cur;
      cur = cur->next;
      cout << cur->val;
    }
    if (op == "SAVE") {
      cin >> x;
      notebook[x] = cur;
      cout << cur->val;
    }
    if (op == "LOAD") {
      cin >> x;
      if (notebook.count(x)) {
        cur = notebook.at(x);
      } else {
        cur = root;
      }
      cout << cur->val;
    }
    if (op == "DELETE") {
      if (cur != root) {
        cur = cur->prev;
      }
      cout << cur->val;
    }
    if (i != (Q-1)) cout << " ";
  }
  cout << endl;
  return 0;
}
