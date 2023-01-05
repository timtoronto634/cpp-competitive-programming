#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int coord[10010][10010];
int overwrap[100010];

int main() {
  int n, leftx, lefty, rightx, righty;
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> leftx >> lefty >> rightx >> righty;
    int lefttopx = leftx, lefttopy = righty, rightbottomx=rightx, rightbottomy=lefty;
    coord[lefttopx][lefttopy]--;
    coord[leftx][lefty]++;
    coord[rightx][righty]++;
    coord[rightbottomx][rightbottomy]--;
  }

  for (int i=0;i<10010;i++) {
    for (int j=1;j<10010;j++) {
      coord[i][j] += coord[i][j-1];
    }
  }
  
  for (int i=1;i<10010;i++) {
    for (int j=0;j<10010;j++) {
      coord[i][j] += coord[i-1][j];
    }
  }

  for (int i=0;i<10010;i++) {
    for (int j=0;j<10010;j++) {
      overwrap[coord[i][j]]++;
    }
  }

  for (int k=1;k<=n;k++) {
    cout << overwrap[k] << endl;
  }
  return 0;
}
