#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a = 2, b = 1;
    int64_t c, n;
    cin >> n;
    if (n==0) {
    cout << 2 << endl;
return 0;
    };
    if (n==1) {
    cout << 1 << endl;
return 0;

    };

    for (int64_t i=1;i<n;i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << endl;
    return 0;
}
