#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    auto a = make_tuple(0, "aa", 24);
    auto b = make_tuple(1, "bb", 32);
    vector<tuple<string, int,int>> v(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int ten;
        string s;
        cin >> s >> ten;
        ten *= -1;
        v.push_back(make_tuple(s, ten, i+1));
    }
    sort(v.begin(), v.end());
    for (int i=0;i<n;i++) {
        cout << get<2>(v.at(i)) << endl;
    }
    return 0;
}
