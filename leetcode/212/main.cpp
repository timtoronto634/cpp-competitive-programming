#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<vector<int>>> location = buildLocationMap(board);

        int m=board.size(), n=board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<string> found;
        for (auto w:words) {
            vector<vector<int>> curidxs = location[w[0]-'a'];
            for (auto curidx : curidxs) {
                int r = curidx[0], c = curidx[1];
                int widx = 0;
                if (backtrackBoard(widx, w, board, r, c, visited))  {
                    found.push_back(w);
                    break;
                }
            }
        }
        return found;
    }

    const int dir[4][2] = {{0,1}, {0, -1}, {1,0}, {-1,0}};
    bool backtrackBoard(int widx, string &word, vector<vector<char>> &board, int r, int c, vector<vector<int>> &visited) {
        if (widx == word.size()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
        if (visited[r][c] == 1) return false;
        if (board[r][c] != word[widx]) return false;
        visited[r][c] = 1;
        for (auto d : dir) {
            if (backtrackBoard(widx+1, word, board, r+d[0], c+d[1], visited)) {
                visited[r][c] = 0;
                return true;
            }
        }
        return false;
    }

    vector<vector<vector<int>>> buildLocationMap(vector<vector<char>>& board) {
        vector<vector<vector<int>>> v(26);
        int m=board.size(), n=board[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                v[board[i][j]-'a'].push_back(vector<int>{i,j});
            }
        }
        return v;
    }
};

int main() {
  Solution s = Solution();
  vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
  vector<string> words = {"ab", "bd", "dd"};
  auto out = s.findWords(board, words);
  vector<vector<int>> visited = {{1,0},{0,0}};
  string word = "ab";
  // cout << s.backtrackBoard(1, word, board, 0, 1, visited) << endl;
  for (auto o : out) {
    cout << o << endl;
  }
  
}