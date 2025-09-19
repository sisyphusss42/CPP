#include <bits/stdc++.h>
using namespace std;

// Set of all element symbols in lowercase
unordered_set<string> elements = {
    "h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca","sc","ti","v","cr","mn","fe",
    "co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in",
    "sn","sb","te","i","xe","cs","ba","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","hf",
    "ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn","fr","ra","ac","th","pa","u","np","pu","am",
    "cm","bk","cf","es","fm","md","no","lr","rf","db","sg","bh","hs","mt","ds","rg","cn","nh","fl","mc","lv","ts","og"
};

string word;
vector<string> solution;
bool found = false;

void dfs(int idx) {
    if (found) return; // stop when solution is found
    if (idx == (int)word.size()) {
        // reached end, print solution
        for (auto &s : solution) cout << "[" << s << "]";
        cout << "\n";
        found = true;
        return;
    }
    // try 1 letter
    if (idx + 1 <= (int)word.size()) {
        string one = word.substr(idx, 1);
        if (elements.count(one)) {
            solution.push_back(one);
            dfs(idx + 1);
            solution.pop_back();
        }
    }
    // try 2 letters
    if (idx + 2 <= (int)word.size()) {
        string two = word.substr(idx, 2);
        if (elements.count(two)) {
            solution.push_back(two);
            dfs(idx + 2);
            solution.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> word)) return 0;

    dfs(0);

    return 0;
}
