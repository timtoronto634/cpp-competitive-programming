#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

// vector<vector<int>> findSubsequences(vector<int>& nums) {
//   vector<vector<int>> found;
//   found.push_back(vector<int>{0,4});
//   return found;
// }

// int numberOfArithmeticSlices(vector<int>& nums) {
//   // get subsequences pair
//   vector<vector<int>> subseqs = findSubsequences(nums);
//   // count all the patterns
//   int sum = 0;
//   for (auto &subseq :subseqs) {
//     int left = subseq[0], right = subseq[1];
//     int nElms = right - left + 1;
//     if (nElms <= 2) continue;
//     sum += ((nElms-3+1) + 1) * (nElms-3+1) / 2;
//   }
//   return sum;
// }

int main () {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i=0;i<n;i++) {
    cin >> nums[i];
  }
  cout << numberOfArithmeticSlices(nums) << endl;
}