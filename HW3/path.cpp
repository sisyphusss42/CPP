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
            con[a].push_back(b);
        }
        lineNumber ++;
    }
    map<int,int> M1;
    for (int i: con[1]){
        M1[i]+=1;
    }

    map<int,int>M2;
    for (const auto& p : M1){
        for (int i: con[p.first]){
            M2[i]+=p.second;
        }
    }

    map<int,int>M3;
    for (const auto& p : M2){
        for (int i: con[p.first]){
            M3[i]+=p.second;
        }
    }

    map<int,int>M4;
    for (const auto& p : M3){
        for (int i: con[p.first]){
            M4[i]+=p.second;
        }
    }

    map<int,int>M5;
    for (const auto& p : M4){
        for (int i: con[p.first]){
            M5[i]+=p.second;
        }
    }
    int n1,n2,n3,n4,n5;
    cin>>n1>>n2>>n3>>n4>>n5;
    cout<<M1[n1]<<" "<<M2[n2]<<" "<<M3[n3]<<" "<<M4[n4]<<" "<<M5[n5]<<endl;
    
    return 0;
}