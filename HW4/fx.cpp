#include <iostream>
#include <string>
#include <utility>
using namespace std;

// find numbers around an operator at position loc
pair<int,int> findNum(const string &s, int loc) {
    int l = loc - 1;
    while (l >= 0 && s[l] == ' ') l--;
    int r = loc + 1;
    while (r < (int)s.size() && s[r] == ' ') r++;

    // parse left number
    int lend = l;
    while (lend >= 0 && isdigit(s[lend])) lend--;
    int leftNum = stoi(s.substr(lend+1, l-lend));

    // parse right number
    int rend = r;
    while (rend < (int)s.size() && isdigit(s[rend])) rend++;
    int rightNum = stoi(s.substr(r, rend-r));

    return make_pair(leftNum, rightNum);
}

string paren(string s) {
    // handle *
    while (s.find('*') != string::npos) {
        int pos = s.find('*');
        auto nums = findNum(s, pos);
        // find substring boundaries
        int l = pos-1; while (l>=0 && s[l]==' ') l--; while (l>=0 && isdigit(s[l])) l--;
        int r = pos+1; while (r<(int)s.size() && s[r]==' ') r++; while (r<(int)s.size() && isdigit(s[r])) r++;
        s = s.substr(0, l+1) + to_string(nums.first * nums.second) + s.substr(r);
    }
    // handle +
    while (s.find('+') != string::npos) {
        int pos = s.find('+');
        auto nums = findNum(s, pos);
        int l = pos-1; while (l>=0 && s[l]==' ') l--; while (l>=0 && isdigit(s[l])) l--;
        int r = pos+1; while (r<(int)s.size() && s[r]==' ') r++; while (r<(int)s.size() && isdigit(s[r])) r++;
        s = s.substr(0, l+1) + to_string(nums.first + nums.second) + s.substr(r);
    }
    return s;
}

int main() {
    string s;
    getline(cin, s);

    // evaluate parentheses
    while (s.find('(') != string::npos) {
        int rightParen = s.find(')');
        int leftParen = rightParen;
        while (leftParen >= 0 && s[leftParen] != '(') leftParen--;
        string inside = s.substr(leftParen+1, rightParen-leftParen-1);
        string val = paren(inside);
        s = s.substr(0, leftParen) + val + s.substr(rightParen+1);
    }

    // evaluate remaining expression
    s = paren(s);
    cout << s << endl;
    return 0;
}
