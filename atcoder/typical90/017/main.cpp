#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct line {ll from; ll to;};

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

long long N, M;

int main() {
  cin >> N >> M;


  vector<line> lines(M);
  int from, to;
  for (int i=0;i<M;i++) {
    cin >> from>> to;
    from--;
    to--;
    lines[i] = line{from,to};
  }

  // 1: same point
  ll numSamePoint = 0;
  ll pointCount[N];
  for (int i=0;i<N;i++) pointCount[i] = 0;
  for (int i=0;i<M;i++) {
    pointCount[lines[i].from]++;
    pointCount[lines[i].to]++;
  }
  ll one = 1;
  ll two = 2;
  for (int i=0;i<N;i++) {
    numSamePoint += pointCount[i] * (pointCount[i]-one) / two;
  }

  // 2: independent
  ll cumulSum[N];
  ll toCount[N];
  for (int i=0;i<N;i++) cumulSum[i]=0;
  for (int i=0;i<N;i++) toCount[i]=0;
  for (int i=0;i<M;i++) {
    toCount[lines[i].to]++;
  }
  cumulSum[0] = toCount[0];
  for (int i=1;i<N;i++) {
    cumulSum[i] = cumulSum[i-1] + toCount[i];
  }
  // calculate
  ll numIndependent = 0;
  for (int i=0;i<M;i++) {
    if (lines[i].from == 0) continue;
    numIndependent += cumulSum[lines[i].from -1];
  }

  // 3: inclusive

  // THIS IS WRONG WAY TO SORT
  // sort(lines.begin(), lines.end(), [](auto const& lhs, auto const& rhs) {
  //   if (lhs.to != rhs.to) return lhs.to < rhs.to;
  //   else return lhs.from < rhs.from;
  // });

	vector<pair<long long, long long>> vec;
	for (int i = 0; i < M; i++) vec.push_back(make_pair(lines[i].to, lines[i].from));
	sort(vec.begin(), vec.end());
  BIT tree;
  tree.init(N);
  ll numInclusive = 0;
  for (int i=0;i<M;i++) {
    auto eachl = vec[i];
    // numInclusive += tree.sumRange(eachl.second, eachl.first);
    numInclusive += (tree.sum(eachl.first-1) - tree.sum(eachl.second));
    tree.add(eachl.second, 1);
  }

	long long Total = M * (M - 1) / 2LL;
	long long SumAns = numSamePoint + numIndependent + numInclusive;
	std::cout << (Total - SumAns) << endl;
	return 0;
}


// 6 3
// 2 5 -> 1 4
// 1 4 -> 0 3
// 1 3 -> 0 2
