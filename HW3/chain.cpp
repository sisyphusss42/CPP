#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ifstream file("com-amazon.ungraph.txt");
    string line;
    int lineNumber = 0;
    int a,b;
    map<int,vector<int>> con;

    while (getline(file, line)) {
        if (lineNumber >= 4) {
            stringstream ss(line);
            ss >> a >> b;
            con[b].push_back(a);
        }
        lineNumber ++;
    }

    int v;
    cin>>v;

    map<int,int> maxCon;

    int indiMaxCon;

    for (const auto& s: con){
        indiMaxCon=0;
        for (int i: s.second){
            if (maxCon[i]>indiMaxCon){
                indiMaxCon=maxCon[i];
            }
        }
        maxCon[s.first] = indiMaxCon + 1;

        if (s.first==v){
            break;
        }
    }

    cout<<maxCon[v]+1<<endl;

    return 0;
}