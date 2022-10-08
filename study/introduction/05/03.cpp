const int MAX_NAME = 16;

// typedef を使うと、 object 宣言時にstructを書かなくて良くなる
typedef struct Student {
  char name[MAX_NAME + 1];
  int scoreJapanese;
  int scoreMath;
  int scoreEnglish;
};

// メンバ/object
Student student;

char str[] = "foo" "bar";