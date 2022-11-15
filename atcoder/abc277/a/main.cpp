#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  vector<char> first{'H' , 'D' , 'C' , 'S'};
  vector<char> sec{'A','2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
  for (int i=0;i<n;i++) {
    string s;
    cin >> s;
    if (find(first.begin(), first.end(), s[0]) == first.end()) {
      cout << "No" << endl;
      return 0;
    }

    if (find(sec.begin(), sec.end(), s[1]) == sec.end()) {
      cout << "No" << endl;
      return 0;
    }
    if (s[0] == s[1]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
    return 0;
}
