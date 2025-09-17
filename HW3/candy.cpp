#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
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
            con[a].push_back(b);
        }
        lineNumber ++;
    }

    vector<int> nodes;
    int tmp;
    for (int i=1;i<=5;i++){
        cin>>tmp;
        nodes.push_back(tmp);
    }

    map<int,long long> candy;
    map<int,long long> change;
    // Initializing the initial state
    for (const auto& p : con){
        candy[p.first]=p.first;
    }

    for (int week=1;week<=6;week++){
        for (const auto& p : con){
            for (int i: p.second){
                change[i]+=floor(candy[p.first]/p.second.size());
            }
            candy[p.first]-= floor(candy[p.first]/p.second.size())*p.second.size();
        }

        for (const auto& p : change){
            candy[p.first]+=p.second;
        }

        if (week==5){
            change.clear();
            continue;
        }
        else if (week==6){
            cout<<candy[nodes[4]]<<endl;
        }
        else{
            cout<<candy[nodes[week-1]]<<" ";
        }
        
        change.clear();
    }

    return 0;
}