#include <bits/stdc++.h>
using namespace std;

int crossProduct(vector<int> a,vector<int> b,vector<int> c) {
  // the cross product of ab, ac
  // vbase = (b[0]-a[0], b[1]-a[1]), varr = (c[0]-a[0], c[1]-a[1])
  return ((b[0]-a[0]) * (c[1]-a[1])) - ((c[0]-a[0])*(b[1]-a[1]));
}

int dotProduct(vector<int> a,vector<int> b,vector<int> c) {
  // vbase = (b[0]-a[0], b[1]-a[1]), varr = (c[0]-a[0], c[1]-a[1])
  return (b[0]-a[0])*(c[0]-a[0]) + (b[1]-a[1])*(c[1]-a[1]);
}

void sortByDotProduct(vector<vector<int>> v) {
  // vbase = (b[0]-a[0], b[1]-a[1]), varr = (c[0]-a[0], c[1]-a[1])
  sort(v.begin(), v.end(), [](vector<int> vecx, vector<int> vecy){
                        return ( vecx[0] < vecy[0] );
                        } )
}

/*
NOTES:
sort : https://kaworu.jpn.org/cpp/std::sort
reverse: https://en.cppreference.com/w/cpp/algorithm/reverse
lambda, this: https://stackoverflow.com/questions/38595834/compilation-error-this-cannot-be-implicitly-captured-in-this-context

graham scan: https://en.wikipedia.org/wiki/Graham_scan
dot product: https://en.wikipedia.org/wiki/Dot_product
convex hull: https://ja.wikipedia.org/wiki/%E5%87%B8%E5%8C%85%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0


*/


/*
class Solution {
public:
    int dotProduct(vector<int> a,vector<int> b,vector<int> c) {
        // vbase = (b[0]-a[0], b[1]-a[1]), varr = (c[0]-a[0], c[1]-a[1])
        return (b[0]-a[0])*(c[0]-a[0]) + (b[1]-a[1])*(c[1]-a[1]);
    }
    int crossProduct(vector<int> a, vector<int> b,vector<int> c) {
        // the cross product of ab, ac
        // vbase = (b[0]-a[0], b[1]-a[1]), varr = (c[0]-a[0], c[1]-a[1])
        return ((b[0]-a[0]) * (c[1]-a[1])) - ((c[0]-a[0])*(b[1]-a[1]));
    }

    bool isBCloser(vector<int> a, vector<int> b,vector<int> c) {
        // the cross product of ab, ac
        // vbase = (b[0]-a[0], b[1]-a[1]), varr = (c[0]-a[0], c[1]-a[1])
        return (abs(b[0]-a[0]) + abs(b[1]-a[1])) < (abs(c[0]-a[0])+abs(c[1]-a[1]));
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 3) return trees;
        // for (int i=1;i<trees.size();i++) {
        //     if (trees[i][1] < p[1]) {
        //         p = trees[i];
        //     } else if (trees[i][1] == p[1] && trees[i][0] < p[0]) {
        //         p = trees[i];
        //     }
        // }
        sort(trees.begin(), trees.end(), [](vector<int> vecx, vector<int> vecy) {
            return ( vecx[1] < vecy[1] )|| (vecx[1] == vecy[1] && vecx[0] < vecy[0]);
        });
        // cout << trees[0][0] << " " << trees[0][1] << endl;
        // cout << p[0] << " " << p[1] << endl;

        vector<int> p = trees[0];
        sort(trees.begin()+1, trees.end(), [this,p](const vector<int> vecx, const vector<int> vecy) {
            int pro = crossProduct(p, vecx, vecy);
            if (pro > 0) return true;
            if (pro == 0) return isBCloser(p, vecx, vecy);
            return false;
        });
        int end = trees.size()-1;
        for (; end>0;end--) {
            if (crossProduct(trees[0], trees[end], trees[end-1]) != 0) break;
        }
        reverse(trees.begin()+end, trees.end());

        printArray(trees);
        int nexti = 2;

        vector<int> prev = trees[0], cur = trees[1];
        vector<vector<int>> path;
        path.push_back(prev);
        path.push_back(cur);
        while (nexti < trees.size()) {
            vector<int> next = trees[nexti];
            if (crossProduct(prev, cur, next) >= 0) {
                // left turn.
                // proceed next point
                prev = cur;
                cur = next;
                path.push_back(next);
                nexti++;
            } else {
                // right turn
                // cur is inside the convex hull. dont need it.
                path.pop_back();
                // keep nexti, and fix prev and cur till cur->next become left turn
                cur = prev;
                if (path.size() < 2) {
                    cout << "error path is empty" << endl;
                    return vector<vector<int>>();
                }
                prev = path[path.size()-2];
            }
        }
        return path;



    }

    void printArray(vector<vector<int>> v) {
        for (int i=0; i<v.size();i++) {
            cout << v[i][0] << " " << v[i][1] << endl;
        }
    }
};

*/