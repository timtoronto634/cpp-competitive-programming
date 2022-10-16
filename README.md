# origin
Original development environment is created in https://github.com/cxconj/kyoprocpp.


# 競プロ C++ 用環境

- VSCode をインストール
- [Remote Development](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack) 拡張を入れる

```bahs
git clone --recursive https://github.com/cxconj/kyoprocpp.git
cd kyoprocpp
code .
# remote conatainer で rebuild container をする.
# Ctrl-shift-P or Cmd-Shift-P(macの場合) で Command Palette を開いて、Remote-Containers: Rebuild Container を選択
```

## acc + oj を使う場合
template.json や template となるファイルは自分で用意。普通に作るとgit 管理外になるので、どこかにbackupあるといいかも
move-it-to-config/ にtemplate の設定とファイルをおいてあるので、それを設定に移すことでも設定可能

コンパイルしてojを実行するコマンドはalias/shortcut に入ってると便利かも
`echo "alias coj='g++ main.cpp -o main && oj t -c ./main'" >> ~/.bashrc`

To use acc command, login is required: `acc login` 
To submit using oj, login is required: `oj login https://atcoder.jp/contests/`


## test.txt を使う場合
何か C++ のプログラムを作る。ここでは例として `hoge.cpp` とする。

```cpp
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#include <bits/stdc++.h>
using namespace std;


int main() {
    int x;
    cin >> x;
    cout << "hello " << x << endl;

    mint y = 998244352;
    cout << (y * 3).val() << endl;

    return 0;
}
```


`test.txt` に標準入力に与える値を書く
```
123
```

実行する
```bash
$ bin/run hoge  # ファイル名から拡張子を取ったものを run command に与える
g++ -g -O2 -Wall -std=gnu++17 -I .    hoge.cpp   -o hoge
./hoge < test.txt
hello 123  # ここからが出力
998244350
```
