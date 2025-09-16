#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> lastVisit;
    lastVisit.push_back(1);
    map<int, int> count;

    ifstream file("com-amazon.ungraph.txt");
    string line;
    int lineNumber = 0;
    int a, b;

    set<int> current(lastVisit.begin(), lastVisit.end());
    vector<int> nextVisit;

    while (getline(file, line)) {
        lineNumber++;
        if (lineNumber >= 5) {
            stringstream ss(line);
            ss >> a >> b;

            if (current.count(a)) {
                count[b]++;
                if (!current.count(b))
                    nextVisit.push_back(b);
            }
            if (current.count(b)) {
                count[a]++;
                if (!current.count(a))
                    nextVisit.push_back(a);
            }
        }
    }

    lastVisit = nextVisit;

    cout << count[88160] << endl;
    for (int i: lastVisit){
        cout<<i<<endl;
    }

    return 0;
}
