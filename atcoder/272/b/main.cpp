#include <bits/stdc++.h>
using namespace std;

void solve() {
    int people;
    int butou;
    cin >> people;
    cin >> butou;
    // create matrix of bool people x people
    vector<vector<bool>> mat(people, vector<bool>(people));
    // for each butou
      int participants;
    for (int b=0;b<butou; b++){
      cin >> participants;
      vector<int> part(participants, 0);
      for (int ip=0;ip<participants;ip++){
        int p;
        cin >> p;
        part[ip] = p-1;
        // cout << part[ip] <<endl;
      }
      for (int ii=0;ii<participants;ii++) {
        for (int jj=ii;jj<participants;jj++) {
          mat[part[ii]][part[jj]] = true;
          mat[part[jj]][part[ii]] = true;
        }
      }
    }
    for (int eachp=0;eachp<people;eachp++) {
      for (int pp=0;pp<people;pp++) {
        // cout << mat[eachp][pp] <<endl;
        if (!(mat[eachp][pp])) {
          cout << "No" <<endl;
          return;
        }
      }
    }
    // for each combination of people (double loop), make the corresponding cell true
    // finally check through matix whether false exists.
    cout << "Yes" << endl;
}

int main() {
    solve();
  return 0;
}
