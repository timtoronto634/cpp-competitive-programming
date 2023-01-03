#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll n, b;
int num_digit;

// f(x) is same when all digits of x is same,
// only consider x with all digits increasing order. (name s)
vector<ll> all_s_ll;


ll calc_f(ll x) {
  if (x == 0) return 0;
  ll res = 1;
  while (x > 0) {
    int digit = x % 10;
    res *= digit;
    x /= 10;
  }
  return res;
}


void dfs(string s, int nex) {
  string nexstr = to_string(nex);
  string ss = s + nexstr;
  if (ss.length() == num_digit) {
    all_s_ll.push_back(stoll(ss));
    return;
  }
  for (int i=nex;i<=9;i++) {
    dfs(ss, i);
  }
  return;
}

void find_all_s() {

  string s = "";
  for (int i=0;i<=9;i++) {
    dfs(s, i);
  }
  return;
}

bool buildable(ll s, ll b, ll fx) {
  ll m = b + fx;
  if (m > n) return false;

  string m_str = to_string(m);
  sort(m_str.begin(), m_str.end());
  return s == stoll(m_str);



}

int main() {
  cin >> n >> b;
  ll patterns = 0;

  num_digit = to_string(n).length();
  find_all_s();

  for (int i=0;i<all_s_ll.size();i++) {
    ll fx = calc_f(all_s_ll[i]);
    if (buildable(all_s_ll[i], b, fx)) patterns++;

  }
  cout << patterns << endl;

  return 0;
}
