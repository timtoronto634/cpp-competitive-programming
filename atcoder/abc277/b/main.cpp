#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n;
  cin >> n;
  vector<char> first{'H' , 'D' , 'C' , 'S'};
  vector<char> sec{'A','2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
  vector<string> sv;
    string s;
  for (int i=0;i<n;i++) {
    cin >> s;
    sv.push_back(s);
  }
  for (int i=0;i<n;i++) {for (int j=i+1;j<n;j++) {if (sv[i]==sv[j]) {
         cout << "No" << endl;
      return 0; 
  }}}
  for (int i=0;i<n;i++) {
    s = sv[i];
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
