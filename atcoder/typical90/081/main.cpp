#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int people[5010][5010];
int cumul[5010][5010];

int main() {
  int n, k, ai, bi;
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> ai >> bi;
    people[ai][bi]++;
  }
  for (int i=0;i<5010;i++) {
    int currow = 0;
    for (int j=0;j<5010;j++) {
      currow += people[i][j];
      cumul[i][j] = currow;
    }
  }
  for (int j=0;j<5010;j++) {
    int curcol = cumul[0][j];
    for (int i=0;i<5010;i++) {
      curcol += cumul[i][j];
      cumul[i][j] = curcol;
    }
  }
  int num_people = 0;
  for (int i=k+1;i<5010;i++) {
    for (int j=k+1;j<5010;j++) {
      num_people = max(num_people, cumul[i][j] - cumul[i-k-1][j] - cumul[i][j-k-1] + cumul[i-k-1][j-k-1]);
    }
  }
  cout << num_people << endl;

  return 0;
}
