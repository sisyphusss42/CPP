#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream file("com-amazon.ungraph.txt");
    string line;
    int lineNumber = 0;
    int a,b;
    vector<pair<int,int>> edge;

    while (getline(file, line)) {
        if (lineNumber >= 4) {
            stringstream ss(line);
            ss >> a >> b;
            edge.push_back(make_pair(a,b));
            edge.push_back(make_pair(b,a));
        }
        lineNumber ++;
    }
    sort(edge.begin(), edge.end());
    
    int n;
    cin>>n;
    cout<<edge[n-1].first<<" "<<edge[n-1].second<<endl;

    return 0;
}