#include <iostream>
using namespace std;

const int MAX_NAME = 16;

// typedef を使うと、 object 宣言時にstructを書かなくて良くなる
struct Student {
  char name[MAX_NAME + 1];
  int scoreJapanese;
  int scoreMath;
  int scoreEnglish;
};

void Show(const Student* pointer){
  cout << "name: " << pointer->name << endl
       << "  japanese: " << pointer->scoreJapanese
       << "  math: " << pointer->scoreMath
       << "  english: " << pointer->scoreEnglish
       << endl;
}

int main() {
  Student student[] = {
    { "akai", 73, 98, 86,},
    { "kasai",64, 45, 40,},
  };
  int size = sizeof student / sizeof *student;

  for (int i=0; i<size; ++i) {
    Show(&student[i]);
  }
};