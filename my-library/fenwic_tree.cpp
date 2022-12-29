#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class BIT {
  public:
    int T[100];

    BIT(int arr[], int size) {
      int square = 1;
      ll sum = 0;
      for (int i=0;i<size;i++) {
        sum += arr[i];
        cout << sum << ", sq: " << square << endl;
        if ((i+1) == square) {
          T[i] = sum;
          square = square << 1;
        } else {
          T[i] = arr[i];
        }
      }
    }

    ll get(int i) {
      return T[i];
    }

    ll getSum(int index) {
      index++;
      ll start = 1;
      while (index > start) {
        if (start << 1 > index) {
          break;
        }
        start <<= 1;
      }
      index--;
      ll sum = T[start-1];
      for (int i = start; i<=index;i++ ) {
        sum += T[i];
      }
      return sum;
    }
};

void check(int expected, int actual) {
  cout << "expected: " << expected;
  cout << ", actual: " << actual;
  cout << endl;
}

// void Init(int arr[]) {
//   for (int i=0;i<5;i++) {
//     arr[i] = i;
//   }
// }

// void Show(int arr[]) {
//   for (int i=0;i<5;i++) {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
//       int size = sizeof(arr)/sizeof(arr[0]);
//       cout << "size: " << size << endl;
// }

int main() {
  int test[5] = {1,2,3,4,5};
  
  int size = sizeof(test)/sizeof(test[0]);
  cout << "size: " << size << endl;
  BIT bit(test, sizeof(test)/sizeof(test[0]));
  bit.get(3);

  check(1, bit.getSum(0));
  check(3, bit.getSum(1));
  check(6, bit.getSum(2));
  check(10, bit.getSum(3));
  check(15, bit.getSum(4));

  check(1, bit.get(0));
  check(3, bit.get(1));
  check(3, bit.get(2));
  check(10, bit.get(3));
  check(5, bit.get(4));

  // int n[5];
  // Init(n);
  // Show(n);
}